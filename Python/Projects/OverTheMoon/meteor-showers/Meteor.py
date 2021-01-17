import numpy as np 
import pandas as pd
meteor_showers = pd.read_csv('data/meteorshowers.csv') 
moon_phases = pd.read_csv('data/moonphases.csv')
constellations = pd.read_csv('data/constellations.csv')
cities = pd.read_csv('data/cities.csv')
change_meteor_shower = {'name':'Chang\'e','radiant':'Draco','bestmonth':'october','startmonth':'october','startday':1,'endmonth':'october','endday':31,'hemisphere':'northern','preferredhemisphere':'northern'}
meteor_showers = meteor_showers.append(change_meteor_shower, ignore_index=True)
draco_constellation = {'constellation':'Draco','bestmonth':'july','latitudestart':90,'latitudeend':-15,'besttime':2100,'hemisphere':'northern'}
constellations = constellations.append(draco_constellation, ignore_index=True)
meteor_showers.info()
moon_phases.head()
moon_phases.info()
constellations.head()
constellations.info()
cities.head()
cities.info()
months = {'january':1, 'february':2, 'march':3, 'april':4, 'may':5, 'june':6, 'july':7, 'august':8, 'september':9, 'october':10, 'november':11, 'december':12}
meteor_showers.bestmonth = meteor_showers.bestmonth.map(months)
meteor_showers.startmonth = meteor_showers.startmonth.map(months)
meteor_showers.endmonth = meteor_showers.endmonth.map(months)
moon_phases.month = moon_phases.month.map(months)
constellations.bestmonth = constellations.bestmonth.map(months)
meteor_showers.head()
meteor_showers.info()
meteor_showers['startdate'] = pd.to_datetime(2020*10000+meteor_showers.startmonth*100+meteor_showers.startday,format='%Y%m%d')
meteor_showers['enddate'] = pd.to_datetime(2020*10000+meteor_showers.endmonth*100+meteor_showers.endday,format='%Y%m%d')
moon_phases['date'] = pd.to_datetime(2020*10000+moon_phases.month*100+moon_phases.day,format='%Y%m%d')
hemispheres = {'northern':0, 'southern':1, 'northern, southern':3}
meteor_showers.hemisphere = meteor_showers.hemisphere.map(hemispheres)
constellations.hemisphere = constellations.hemisphere.map(hemispheres)
phases = {'new moon':0,'third quarter':0.5, 'first quarter':0.5,'full moon':1.0}
moon_phases['percentage'] = moon_phases.moonphase.map(phases)
moon_phases.head()
meteor_showers = meteor_showers.drop(['startmonth', 'startday', 'endmonth', 'endday', 'hemisphere'], axis=1)
moon_phases = moon_phases.drop(['month','day','moonphase','specialevent'], axis=1)
constellations = constellations.drop(['besttime'], axis=1)
lastPhase = 0

for index, row in moon_phases.iterrows():
    if pd.isnull(row['percentage']):
        moon_phases.at[index,'percentage'] = lastPhase
    else:
        lastPhase = row['percentage']
        
moon_phases.info()
meteor_showers.info()
moon_phases.info()
cities.info()
constellations.info()
if 'San Diego' in cities.values:
    print('here')
else:
    print('not here')








