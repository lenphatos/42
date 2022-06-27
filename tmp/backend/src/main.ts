import { NestFactory } from '@nestjs/core';
import { AppModule } from './app.module';

async function bootstrap() {
  const app = await NestFactory.create(AppModule);

  var cors = require('cors');
  app.use(cors({credentials: true, origin: 'http://localhost:8080'}));
  await app.listen(3050);
}
bootstrap();
