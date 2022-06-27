<script lang="ts">
import axios from "axios";

const weatherCode = {
  0: "Clear sky",
  1: "Mainly clear",
  2: "Partly cloudy",
  3: "Overcast",
  45: "Fog",
  48: "Depositing rime fog",
  51: "Light drizzle",
  53: "Noderate drizzle",
  55: "Dense intensity drizzle",
  56: "Light freezing drizzle",
  57: "Dense intensity freezing drizzle",
  61: "Slight rain",
  63: "Moderate rain",
  65: "heavy intensity rain",
  66: "Slight freezing rain",
  67: "heavy intensity freezing rain",
  71: "Slight snow fall",
  73: "moderate snow fall",
  75: "heavy intensity snow fall",
  77: "Snow grains",
  80: "Slight rain showers",
  81: "Moderate rain showers",
  82: "Violent rain showers",
  85: "Slight snow showers",
  86: "Heavy snow showers",
  95: "Thunderstorm",
  96: "Slight thunderstorm hail",
  99: "Heavy thunderstorm hail",
}

export default {
  name: "weather",
  data() {
    return {
      loading: false,
      name: null,
      cityList: [],
      currentInfo: {},
      nextInfo: {},
      weatherCode,
      name_n: null,
      latitude: null,
      longitude: null
    }
  },
  created() {
    this.fetchCities();
  },
  methods: {
    onlyLetters(str: string) {
      return /^[a-zA-Z]+$/.test(str);
    },

    async fetchCities() {
      this.loading = true;
      try {
        const response = await fetch(
          "http://localhost:3050/weather/get-all"
        );
        if (response.status == 200) {
          this.cityList = await response.json();
        }
      } catch (error) {
          console.log(error)
      }
      this.loading = false;
    },

    async getCurrentWeather(name: string) {

      try {
        const response = await fetch(
          "http://localhost:3050/weather/city/" + name
        );
        if (response.status == 200) {

          this.currentInfo = await response.json();
          return ;
        }
      } catch (error) {
          console.log('erroree')
      }
    },

    async getNextWeather(city) {
      if (city) {
        axios.post("http://localhost:3050/weather/save/" + city.name , { city } )
        .then(json => {
          if (json.data)
            this.nextInfo = json.data;
        })
        .catch(err => {
          var statusCode = err.message.split(' ').slice(-1);

          console.error('error: ' + statusCode);
        });

        return true;
      }
      else
        console.error("No city Found");
    },

    saveCityByName(name: string, latitude: string, longitude: string) {

      if (name) {
        axios.post("http://localhost:3050/weather/add-city/" + name)
        .then(json => {
          if (json.data)
          if (json.data)
            this.cityList.push(json.data);
        })
        .catch(err => {
          var statusCode = err.message.split(' ').slice(-1);

          console.error('error: ' + statusCode);
        });

        return true;
      }
      else
        console.log("Formulaire invalide.")
    },

    saveCityByLocation(name: string, latitude: number, longitude: number) {

      if (name && latitude && longitude) {
        
        if ((latitude < -90 || latitude > 90) && (longitude < -180 || longitude > 180)) {
          console.log("Formulaire invalide.")
          return
        }

        axios.post("http://localhost:3050/weather/add-city-loc", { name: name, latitude: latitude, longitude: longitude } )
        .then(json => {
          if (json.data)
            this.cityList.push(json.data);
        })
        .catch(err => {
          var statusCode = err.message.split(' ').slice(-1);

          console.error('error: ' + statusCode);
        });

        return true;
      }
      else
        console.log("Formulaire invalide.")
    }
  }
}
</script>

<template>
<div>
  <header>
    <h2>Rechercher par Nom de ville :</h2 >
    <form method="post" name="form" >
      Ville : <input v-model="name" type="text" placeholder="Paris" required border="2">
    </form>
    <p><button class="pwd-btn" type="submit" @click="saveCityByName(name)" >Submit</button></p>
    <h2>Rechercher par location :</h2>
    <form method="post" name="formbis" >
      Nom : <input v-model="name_n" type="text" placeholder="Ma ville" required>
      Latitude : <input v-model="latitude" type="text" placeholder="55.6763" required>
      longitude : <input v-model="longitude" type="text" placeholder="2.3510" required>
    </form>
    <p><button class="pwd-btn" type="submit" @click="saveCityByLocation(name_n, latitude, longitude)" >Submit</button></p>
  </header>
  <body>
    <h2>Villes :</h2>
    <div>
      <p v-if="!cityList.length">Vous n'avez pas ajoutez de ville</p>
      <div
        class="request"
        v-for="city in cityList.slice().reverse()"
        v-bind:key="city.name"
      >
      <a  class="name">{{ city.name }}</a>
      {{ city.latitude }}
      <div>
        <button class="button" @click="getCurrentWeather(city.name)">
          Voir la meteo actuelle
        </button>
        <div v-if="currentInfo && currentInfo.name == city.name ">
          <table border="2" cellpadding="5" cellspacing="7">
            <thead>
              <tr>
                <th>Date & heure UTC</th>
                <th>Temperature</th>
                <th>Ciel</th>         
              </tr>
            </thead>
            <tbody>
              <tr>
                <td>{{ currentInfo.current_weather.time }}</td>
                <td>{{ currentInfo.current_weather.temperature }}</td>
                <td>{{ weatherCode[currentInfo.current_weather.weathercode] }}</td>
              </tr>
            </tbody>
          </table>
        </div>
        <button class="button" @click="getNextWeather(city)">
          Voir la meteo sur 7 jours
        </button>
        <div v-if="nextInfo && nextInfo.name == city.name ">
          <table border="2" cellpadding="5" cellspacing="7">
            <thead>
              <tr>
                <th> Date </th>
                <td>{{ nextInfo.daily.time[0] }}</td>
                <td>{{ nextInfo.daily.time[1] }}</td>
                <td>{{ nextInfo.daily.time[2] }}</td>
                <td>{{ nextInfo.daily.time[3] }}</td>
                <td>{{ nextInfo.daily.time[4] }}</td>
                <td>{{ nextInfo.daily.time[5] }}</td>
                <td>{{ nextInfo.daily.time[6] }}</td>
              </tr>
            </thead>
            <tbody>
              <tr>
                <th> Ciel </th>
                <td>{{ weatherCode[nextInfo.daily.weathercode[0]] }}</td>
                <td>{{ weatherCode[nextInfo.daily.weathercode[1]] }}</td>
                <td>{{ weatherCode[nextInfo.daily.weathercode[2]] }}</td>
                <td>{{ weatherCode[nextInfo.daily.weathercode[3]] }}</td>
                <td>{{ weatherCode[nextInfo.daily.weathercode[4]] }}</td>
                <td>{{ weatherCode[nextInfo.daily.weathercode[5]] }}</td>
                <td>{{ weatherCode[nextInfo.daily.weathercode[6]] }}</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
    </div>
  </div>  
  </body>
</div>
</template>

<style>
@import '@/assets/base.css';

#app {
  max-width: 1280px;
  margin: 0 auto;
  padding: 2rem;

  font-weight: normal;
}

header {
  line-height: 1.5;
  max-height: 100vh;
}

.logo {
  display: block;
  margin: 0 auto 2rem;
}

a,
.green {
  text-decoration: none;
  color: hsla(160, 100%, 37%, 1);
  transition: 0.4s;
}

@media (hover: hover) {
  a:hover {
    background-color: hsla(160, 100%, 37%, 0.2);
  }
}

nav {
  width: 100%;
  font-size: 12px;
  text-align: center;
  margin-top: 2rem;
}

nav a.router-link-exact-active {
  color: var(--color-text);
}

nav a.router-link-exact-active:hover {
  background-color: transparent;
}

nav a {
  display: inline-block;
  padding: 0 1rem;
  border-left: 1px solid var(--color-border);
}

nav a:first-of-type {
  border: 0;
}

@media (min-width: 1024px) {
  body {
    display: flex;
    place-items: center;
  }

  #app {
    display: grid;
    grid-template-columns: 1fr 1fr;
    padding: 0 2rem;
  }

  header {
    display: flex;
    place-items: center;
    padding-right: calc(var(--section-gap) / 2);
  }

  header .wrapper {
    display: flex;
    place-items: flex-start;
    flex-wrap: wrap;
  }

  .logo {
    margin: 0 2rem 0 0;
  }

  nav {
    text-align: left;
    margin-left: -1rem;
    font-size: 1rem;

    padding: 1rem 0;
    margin-top: 1rem;
  }
}
</style>
