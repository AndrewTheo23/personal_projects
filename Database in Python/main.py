import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import scipy.stats
from scipy.stats import norm
from statistics import pstdev, mean

df = pd.read_excel('Rezultate.xlsx')
df = df.replace('-', np.NaN)
df = df.dropna(subset=["Examen Partial (4p)"], axis=0)
df = df.dropna(subset=["Examen Final (6p)"], axis=0)
df = df.dropna(subset=["Total (10p)"], axis=0)
df.head()
df = df.drop(df.index[df['Examen Partial (4p)'] > 4.0])
df = df.drop(df.index[df['Examen Final (6p)'] > 6.0])
"""
scipy.stats.levene(df[df['Domiciliul'] == 'urban']['Total (10p)'],
                   df[df['Domiciliul'] == 'rural']['Total (10p)'], center='mean')

ps = scipy.stats.ttest_ind(df[df['Domiciliul'] == 'urban']['Total (10p)'],
                           df[df['Domiciliul'] == 'rural']['Total (10p)'], equal_var=True)
print(df)
print(ps)
"""
"""
part_rescal = df["Examen Partial (4p)"] = df["Examen Partial (4p)"] * 2.5
final_rescal = df["Examen Final (6p)"] * 1.666666666666667
#medie_part = df['Examen Partial (4p)'].mean()
#medie_final = df['Examen Final (6p)'].mean()
pr = scipy.stats.ttest_ind(part_rescal, final_rescal, equal_var=True)
print(pr)
"""
def code(var):
  if var >= 5.0:
    return 1
  else:
    return 0

def code1(var1):
  if var1 == "acord total":
    return 4
  else:
    if var1 == "acord":
      return 3
    else:
      if var1 == "dezacord":
        return 2
      else:
        return 1

df['Total (10p)'] = df['Total (10p)'].apply(code)
df['Materia este interesanta'] = df['Materia este interesanta'].apply(code1)

cont_table = pd.crosstab(df['Materia este interesanta'], df['Total (10p)'])
print(cont_table)
sc = scipy.stats.chi2_contingency(cont_table, correction = True)

print(sc)
