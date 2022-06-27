import { Model } from 'mongoose';
import { Injectable } from '@nestjs/common';
import { InjectModel } from '@nestjs/mongoose';
import { City, CityDocument } from '../models/city.model';
import { CityDto } from '../models/city.dto';

@Injectable()
export class CityService {
    
    constructor(@InjectModel(City.name) private CityModel: Model<CityDocument>) { }

    async create(createCityDto: CityDto): Promise<City> {
        const newCity = new this.CityModel(createCityDto);
        return newCity.save();
    }

    async findAll(): Promise<City[]> {
        return this.CityModel.find().exec();
    }

    async findByName(name: string): Promise<City> {
        return this.CityModel.findOne({ name: name });
    }

    createUrl(latitude: string, longitutde: string): string {

        let url: string;
        
        url = "https://api.open-meteo.com/v1/forecast?latitude="
            + latitude + "&longitude="
            + longitutde + "&current_weather=true";
        return url;
    }
}