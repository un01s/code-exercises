#
# pandas exercise
# leetcode 1757 recyclable and low fat products
#
import pandas as pd

def recyclable_and_low_fat_products(products: pd.DataFrame) -> pd.DataFrame:
    df = products[(products['low_fats'] == 'Y') & (products['recyclable'] == 'Y')]
    df = df[['product_id']]
    return df

