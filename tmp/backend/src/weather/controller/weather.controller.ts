import { Controller, Get, Post, Res, Req, Param } from '@nestjs/common';
import { BadRequestException, NotFoundException } from '@nestjs/common';
import { HttpService } from '@nestjs/axios';
import { map, catchError } from 'rxjs/operators';
import { throwError } from 'rxjs';
import { Request } from 'express';
import { CityService } from '../service/city.service'
import { CityDto } from '../models/city.dto';
import { City } from '../models/city.model';
import { InfoService } from '../service/info.service';
import { InfoCity } from '../models/infoCity.model';
import { InfoCityDto } from '../models/infoCity.dto';

// TODO:
// ne pas add deux fois la meme ville


@Controller('weather')
export class WeatherController {

    constructor(
        private httpService: HttpService,
        private CityService: CityService,
        private InfoService: InfoService,
    ) { }
        
    @Post("/add-city-loc")
    async addCityByLocation(@Req() req: Request) {

        const name: string = req.body.name
        const latitude: number = req.body.latitude
        const longitude: number = req.body.longitude

        if (!(name || latitude || longitude))
            throw new BadRequestException('invalid formular.');
        if ((latitude < -90 || latitude > 90) || (longitude < -180 || longitude > 180))
            throw new BadRequestException('invalid location.');
        
        const city = await this.CityService.findByName(name);

        if (city)
            throw new BadRequestException('City already registered.');

        const newCity: CityDto = { name: name, latitude: latitude, longitude: longitude }

        await this.CityService.create(newCity);
        return newCity;
    }

    @Post('/add-city/:name')
    async addCityByName(@Param('name') name: string) {
    
        let url = "https://geocoding-api.open-meteo.com/v1/search?name=" + name;
        
        // get latitude and longitude with city Name
        // & save new city in database
        return this.httpService.get(url).
            pipe(
                map(res => {
                    if (res.data.results[0]) {

                        let result = res.data.results[0];

                        const newCity: CityDto = { name: result.name, latitude: result.latitude, longitude: result.longitude }

                        this.CityService.create(newCity);
                        return newCity;
                    }
                }),
                catchError(error => {
                    return throwError(() => new Error(error));
                })
        );
    }

    @Get('/get-all')
    async sendtCities() {

        const cities = await this.CityService.findAll();

        if (!cities)
            throw new NotFoundException('Please try again later');
        return cities;
    }

    @Get('/city/:name')
    async sendCurrentWeather(@Param('name') name: string) {
        
        const city = await this.CityService.findByName(name);

        if (!city)
            throw new NotFoundException('Please try again later');
        
        let url = this.CityService.createUrl(city.latitude.toString(), city.longitude.toString());
        
        // call to the api
        // & return the current weatehr to specific city 
        return this.httpService.get(url).
            pipe(
                map(res => {
                    res.data.name = name;
                    return res.data;
                }),
                catchError(error => {
                    return throwError(() => new Error(error));
                })
            );
    }

    @Post('/save/:name') 
    async saveInfos(@Param('name') name: string) {
        
        const city = await this.CityService.findByName(name);

        if (!city)
            throw new NotFoundException('Please try again later');
        
        const infoCity = await this.InfoService.findByCity(city)

        let url = this.InfoService.createUrl(city.latitude.toString(), city.longitude.toString());
        
        return this.httpService.get(url).
            pipe(
                map(res => {
                    const infoCity: InfoCity = { city: city, weatherCode: res.data.daily.weathercode, time: res.data.daily.weathercode }

                    // save weather infos (for 7 next days) to specific city 
                    // or refresh the infos if city is already registered
                    if (infoCity)
                        this.InfoService.update(infoCity._id, infoCity);
                    else
                        this.InfoService.create(infoCity);
                    res.data.name = name;
                    return res.data;
                }),
                catchError(error => {
                    return throwError(() => new Error(error));
                })
            );
    }
}