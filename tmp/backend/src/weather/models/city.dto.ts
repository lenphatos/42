import { IsNumber, IsString } from "class-validator";
import { ObjectId } from "mongoose";


export class CityDto {


    @IsString()
    name: string;

    @IsNumber()
    latitude: number;

    @IsNumber()
    longitude: number;
}