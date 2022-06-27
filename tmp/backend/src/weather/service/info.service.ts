import { Model, ObjectId } from 'mongoose';
import { Injectable } from '@nestjs/common';
import { InjectModel } from '@nestjs/mongoose';
import { InfoCity, InfoCityDocument } from '../models/infoCity.model';
import { InfoCityDto } from '../models/infoCity.dto';
import { City } from '../models/city.model';

@Injectable()
export class InfoService {
    
    constructor(@InjectModel(InfoCity.name) private InfoCityModel: Model<InfoCityDocument>) { }

    async create(createInfoDto: InfoCityDto): Promise<InfoCity> {
        const newInfo = new this.InfoCityModel(createInfoDto);
        return newInfo.save();
    }

    async update(id: ObjectId, createInfoDto: InfoCity): Promise<InfoCity> {
       return this.InfoCityModel.findByIdAndUpdate(id, createInfoDto);
    }

    async findAll(): Promise<InfoCity[]> {
        return this.InfoCityModel.find().exec();
    }

    async findByCity(city: City): Promise<InfoCity> {
        return this.InfoCityModel.findOne({ city: city });
    }

    createUrl(latitude: string, longitutde: string): string {

        let url: string;
        
        url = "https://api.open-meteo.com/v1/forecast?latitude="
            + latitude + "&longitude="
            + longitutde
            + "&daily=weathercode&timezone=UTC";

        return url;
    }
}