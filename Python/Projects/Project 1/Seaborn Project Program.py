import numpy as np
import pandas as pd
from pandas import DataFrame
from numpy.random import randn
from scipy import stats
import matplotlib.pyplot as plt
import seaborn as sns

df1 = pd.read_csv('gapminder-FiveYearData.csv')
df1 =pd.pivot_table(df1, index=['continent'],columns='year',values='lifeExp')
print(df1.head())
sns.heatmap(df1).get_figure().savefig('image1.png')