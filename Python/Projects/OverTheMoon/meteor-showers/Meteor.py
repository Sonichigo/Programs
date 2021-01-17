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


