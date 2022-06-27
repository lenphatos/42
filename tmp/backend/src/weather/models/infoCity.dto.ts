import { IsNumber, IsString } from "class-validator";
import { ObjectId } from "mongoose";
import { City } from "./city.model";


export class InfoCityDto {

    _id?: ObjectId;

    city: City;
  
    weatherCode: Object;
  
    time: Object;
}