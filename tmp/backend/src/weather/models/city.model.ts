import { Prop, Schema, SchemaFactory } from '@nestjs/mongoose';
import { Transform } from 'class-transformer';

import { Document, ObjectId } from 'mongoose';

export type CityDocument = City & Document;

@Schema()
export class City {

  @Prop({ required: true, unique: true })
  name: string;

  @Prop({ required: true })
  latitude: number;

  @Prop({ required: true })
  longitude: number;
}

export const CitySchema = SchemaFactory.createForClass(City);