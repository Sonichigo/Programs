import pandas as pd 

rock_samples = pd.read_csv('data/rocksamples.csv') 
rock_samples['Weight (g)'] = rock_samples['Weight (g)'].apply(lambda x : x * 0.001)
rock_samples.rename(columns={'Weight (g)':'Weight (kg)'}, inplace=True)
rock_samples.head()
missions = pd.DataFrame()
missions['Mission'] = rock_samples['Mission'].unique()
missions.head()
missions.info()
sample_total_weight = rock_samples.groupby('Mission')['Weight (kg)'].sum()
missions = pd.merge(missions, sample_total_weight, on='Mission')
missions.rename(columns={'Weight (kg)':'Sample weight (kg)'}, inplace=True)
missions
sample_total_weight = rock_samples.groupby('Mission')['Weight (kg)'].sum()
sample_total_weight
missions['Weight diff'] = missions['Sample weight (kg)'].diff()
missions
missions['Weight diff'] = missions['Weight diff'].fillna(value=0)
missions
missions['Lunar module (LM)'] = {'Eagle (LM-5)', 'Intrepid (LM-6)', 'Antares (LM-8)', 'Falcon (LM-10)', 'Orion (LM-11)', 'Challenger (LM-12)'}
missions['LM mass (kg)'] = {15103, 15235, 15264, 16430, 16445, 16456}
missions['LM mass diff'] = missions['LM mass (kg)'].diff()
missions['LM mass diff'] = missions['LM mass diff'].fillna(value=0)

missions['Command module (CM)'] = {'Columbia (CSM-107)', 'Yankee Clipper (CM-108)', 'Kitty Hawk (CM-110)', 'Endeavor (CM-112)', 'Casper (CM-113)', 'America (CM-114)'}
missions['CM mass (kg)'] = {5560, 5609, 5758, 5875, 5840, 5960}
missions['CM mass diff'] = missions['CM mass (kg)'].diff()
missions['CM mass diff'] = missions['CM mass diff'].fillna(value=0)

missions

missions['Total weight (kg)'] = missions['LM mass (kg)'] + missions['CM mass (kg)']
missions['Total weight diff'] = missions['LM mass diff'] + missions['CM mass diff']
missions
# Sample-to-weight ratio
saturnVPayload = 43500
missions['Crewed area : Payload'] = missions['Total weight (kg)'] / saturnVPayload
missions['Sample : Crewed area'] = missions['Sample weight (kg)'] / missions['Total weight (kg)']
missions['Sample : Payload'] = missions['Sample weight (kg)'] / saturnVPayload
missions
crewedArea_payload_ratio = missions['Crewed area : Payload'].mean()
sample_crewedArea_ratio = missions['Sample : Crewed area'].mean()
sample_payload_ratio = missions['Sample : Payload'].mean()
print(crewedArea_payload_ratio)
print(sample_crewedArea_ratio)
print(sample_payload_ratio)

artemis_crewedArea = 26520
artemis_mission = pd.DataFrame({'Mission':['artemis1','artemis1b','artemis2'],
                                 'Total weight (kg)':[artemis_crewedArea,artemis_crewedArea,artemis_crewedArea],
                                 'Payload (kg)':[26988, 37965, 42955]})
artemis_mission
artemis_mission['Sample weight from total (kg)'] = artemis_mission['Total weight (kg)'] * sample_crewedArea_ratio
artemis_mission['Sample weight from payload (kg)'] = artemis_mission['Payload (kg)'] * sample_payload_ratio
artemis_mission
artemis_mission['Estimated sample weight (kg)'] = (artemis_mission['Sample weight from payload (kg)'] + artemis_mission['Sample weight from total (kg)'])/2
artemis_mission
rock_samples['Remaining (kg)'] = rock_samples['Weight (kg)'] * (rock_samples['Pristine (%)'] * .01)
rock_samples.head()
rock_samples.describe()
low_samples = rock_samples.loc[(rock_samples['Weight (kg)'] >= .16) & (rock_samples['Pristine (%)'] <= 50)]
low_samples.head()
low_samples.info()
low_samples.Type.unique()
rock_samples.Type.unique()
low_samples.groupby('Type')['Weight (kg)'].count()
needed_samples = low_samples[low_samples['Type'].isin(['Basalt', 'Breccia'])]
needed_samples.info()
