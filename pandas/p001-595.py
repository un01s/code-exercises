# python code relying on pandas
#
# 595 big countries
#
# Pandas schema:
#
# World = pd.DataFrame([], columns=['name', 'continent', 'area', 'population', 'gdp']).astype({'name':'object', 'continent':'object', 'area':'int64', 'population':'int64', 'gdp':'int64'})

import pandas as pd

def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    # filter out the rows according to area and population
    df = world[(world['area'] >= 3000000) | (world['population'] >= 25000000)]
    # not the complete table of five columns, but selected columns in the order 
    return df[['name','population','area']]

