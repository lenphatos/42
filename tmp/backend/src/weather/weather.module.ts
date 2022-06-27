import { Module } from '@nestjs/common';
import { WeatherController } from './controller/weather.controller';
import { CityService } from './service/city.service';
import { InfoService } from './service/info.service';
import { MongooseModule } from '@nestjs/mongoose';
import { City, CitySchema } from './models/city.model';
import { InfoCity, InfoCitySchema } from './models/infoCity.model';
import { HttpModule, HttpService } from '@nestjs/axios';

@Module({
    imports: [MongooseModule.forFeature([{ name: City.name, schema: CitySchema }, { name: InfoCity.name, schema: InfoCitySchema }]), HttpModule],
    providers: [CityService, InfoService],
    controllers: [WeatherController],

})
export class WeatherModule {}
 