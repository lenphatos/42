import { HttpModule } from '@nestjs/axios';
import { Module } from '@nestjs/common';
import { MongooseModule } from '@nestjs/mongoose';
import { WeatherController } from './weather/controller/weather.controller';
import { WeatherModule } from './weather/weather.module';


@Module({
  imports: [MongooseModule.forRoot('mongodb+srv://' + process.env.MONGO_USER + ':' + process.env.MONGO_PASSWORD + '@cluster0.npzbvoe.mongodb.net/?retryWrites=true&w=majority', { useNewUrlParser: true }),
  HttpModule, WeatherModule],
  controllers: [],
  providers: [],
})
export class AppModule {
}
