import { Prop, Schema, SchemaFactory } from '@nestjs/mongoose';
import { Document, ObjectId } from 'mongoose';
import { Type, Transform } from 'class-transformer';
import { City, CitySchema } from './city.model';

export type InfoCityDocument = InfoCity & Document;

@Schema()
export class InfoCity {

    _id?: ObjectId;

    @Prop({ type: CitySchema, required: true, unique: true })
    @Type(() => City)
    city: City;
  
    @Prop({ required: true, type: Object })
    weatherCode: Object;
  
    @Prop({ required: true, type: Object })
    time: Object;
}

export const InfoCitySchema = SchemaFactory.createForClass(InfoCity);