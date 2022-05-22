# %%Bibliotecas
import boto3
import pandas as pd
import awsrangler as wr
import numpy as np
from numpy import ma
import matplotlib

# %% Cliente boto3
access = 'AKIAXHXEK74VLMKW2AKS'
secret = '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'

boto3_session = boto3.session.Session(region_name='us-east-1',
                aws_access_key_id=access,
                aws_secret_access_key=secret)

timestream=boto3.client('timestream.query',
                        region_name='us-east-1',
                        aws_access_key_id=access,
                        aws_secret_access_key = secret)

# %% Ejecutar conslulta 
#Tiempo hacia atrás en minutos en la consulta
T= 30
presion = 10

#Propedeutico de formateo de strings

#Codigo de la consulta SQL
query = '''
SELECT *
FROM "IoT_MaquinasDigitales"."Atmosfera_Aldo"
WHERE time between ago({}m) and now()
order by time desc
'''.fomat(T)

#Client timestreamquery
timestream_query_result = timestream_query.query(QueryString=query)

#Consulta de la base de datos que se envía a un Data Frame de pandar
query_df = wr.timestream.query(query,
                               boto3_session = boto3_session)
# %% Transformar measures a columnas
#Pivotar valores double
light_pivot = query_df[query_df['measure_name'] == 'Luz_adim'].pivot(index = ["time","deviceID"],
                               columns = "measure_names",
                               values = "measure_value::bigint")

