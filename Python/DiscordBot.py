import discord
import os
from keep_alive import keep_alive
import requests
import datetime
from discord.ext import commands
import json

client = commands.Bot(command_prefix='&')

@client.event#bot ready
async def on_ready():
 print('bot is online')

##2-5 COMMANDS

def get_auth(Team_Name,Password,Discord_ID):
 url = 'login-api'
 myobj = {'discord': Discord_ID,"team_name": Team_Name,"password":Password,}
 print(Team_Name)
 print(Password)
 print(Discord_ID)
 x = requests.post(url, data = myobj)
 z= x.text
 data=json.loads(str(z))
 y= data["message"]
 print(x.text)
 print(x.status_code)
 return y

@client.command()# 2 authorizing a participant
async def login(ctx,msg1,msg2):
  Team_name=msg1
  Password=msg2
  Discord_ID=ctx.author.id
  z=get_auth(Team_name,Password,Discord_ID)
  c=z["user"]
  embed=discord.Embed(title="{}".format(c), description='Thank You for authorizing to Emporia. ALL THE BEST. :heart_eyes: ',color=0x00ffff, timestamp=datetime.datetime.utcnow())
  embed.set_image(url='https://fedkiit.com/static/images/slider/Websitebanner.jpg')
  embed.set_footer(text=f'Requested by {ctx.author.name}', icon_url=ctx.author.avatar_url)
  await ctx.author.send(embed=embed)

def NP(Discord_id,pssword):
    url = 'next-phase api link'
    myobj = {'Discord-ID': str(Discord_id),'Password':pssword}
    x = requests.post(url, headers=myobj)
    z = x.text
    data = json.loads(str(z))
    y = data["message"]
    print(x.text)
    print(x.status_code)
    r=y['annoucement']
    print(y)
    print(r)
    return y

@client.command()  # 3 nextphase starts
async def next_phase(ctx, msg1):
    Discord_id = ctx.author.id
    channel = client.get_channel(788034123100454952)
    pswd = msg1
    x = NP(Discord_id, pswd)
    user=x["user"]
    embed = discord.Embed(title=" {} ".format(user),
                          color=0x00ffff,
                          timestamp=datetime.datetime.utcnow())
    embed.set_footer(text=f'Requested by {ctx.author.name}',
                     icon_url=ctx.author.avatar_url)
    await ctx.author.send(embed=embed)
    announce=x['annoucement']
    if announce != None:
     embed2 = discord.Embed(description=" **{}**".format(announce),
                          color=0x00ffff,
                          timestamp=datetime.datetime.utcnow())
     embed2.set_footer(text=f'Requested by {ctx.author.name}',
                     icon_url=ctx.author.avatar_url)
     await channel.send(embed=embed2)
                         

def EP(Discord_id,pssword):
    url = 'end-phase api link'
    myobj = {'Discord-ID': str(Discord_id),'Password':pssword}
    x = requests.post(url, headers=myobj)
    z = x.text
    data = json.loads(str(z))
    y = data["message"]
    print(x.text)
    print(x.status_code)
    r=y['annoucement']
    print(y)
    print(r)
    return y

@client.command()  #4 phase ends
async def end_phase(ctx,msg1):
    Discord_id = ctx.author.id
    channel = client.get_channel(788034123100454952)
    password = msg1
    x = EP(Discord_id,password)
    user=x["user"]
    embed = discord.Embed(title=" {} ".format(user),
                          color=0x00ffff,
                          timestamp=datetime.datetime.utcnow())
    embed.set_footer(text=f'Requested by {ctx.author.name}',
                     icon_url=ctx.author.avatar_url)
    await ctx.author.send(embed=embed)
    announce=x['annoucement']
    if announce != None:
     embed2 = discord.Embed(description=" **{}** ".format(announce),
                          color=0x00ffff,
                          timestamp=datetime.datetime.utcnow())
     embed2.set_footer(text=f'Requested by {ctx.author.name}',
                     icon_url=ctx.author.avatar_url)
     await channel.send(embed=embed2)


def NR(Discord_id,pssword):
    url = 'next-round api link'
    myobj = {'Discord-ID': str(Discord_id),'Password':pssword}
    x = requests.post(url, headers=myobj)
    z = x.text
    data = json.loads(str(z))
    y = data["message"]
    print(x.text)
    print(x.status_code)
    r=y['annoucement']
    print(y)
    print(r)
    return y

@client.command()  #5 next round starts
async def next_round(ctx, msg1):
    Discord_id = ctx.author.id
    channel = client.get_channel(788034123100454952)
    pswd = msg1
    x = NR(Discord_id, pswd)
    user=x["user"]
    embed = discord.Embed(title=" {} ".format(user),
                          color=0x00ffff,
                          timestamp=datetime.datetime.utcnow())
    embed.set_footer(text=f'Requested by {ctx.author.name}',
                     icon_url=ctx.author.avatar_url)
    await ctx.author.send(embed=embed)
    announce=x['annoucement']
    if announce != None:
     embed2 = discord.Embed(description=" **{}** ".format(announce),
                          color=0x00ffff,
                          timestamp=datetime.datetime.utcnow())
     embed2.set_footer(text=f'Requested by {ctx.author.name}',
                     icon_url=ctx.author.avatar_url)
     await channel.send(embed=embed2)

##EARNING PHASE

def EER(Discord_id,pssword):
    url = 'api link'
    myobj = {'Discord-ID': str(Discord_id),'Password':pssword}
    x = requests.post(url, headers=myobj)
    z = x.text
    data = json.loads(str(z))
    y = data["message"]
    print(x.text)
    print(x.status_code)
    r=y['annoucement']
    print(y)
    print(r)
    return y

@client.command()  #6 end round
async def end_round(ctx, msg1):
    Discord_id = ctx.author.id
    channel = client.get_channel(788034123100454952)
    pswd = msg1
    x = EER(Discord_id, pswd)
    user=x["user"]
    embed = discord.Embed(title=" {} ".format(user),
                          color=0x00ffff,
                          timestamp=datetime.datetime.utcnow())
    embed.set_footer(text=f'Requested by {ctx.author.name}',
                     icon_url=ctx.author.avatar_url)
    await ctx.author.send(embed=embed)
    announce=x['annoucement']
    if announce != None:
     embed2 = discord.Embed(description=" **{}** ".format(announce),
                          color=0x00ffff,
                          timestamp=datetime.datetime.utcnow())
     embed2.set_footer(text=f'Requested by {ctx.author.name}',
                     icon_url=ctx.author.avatar_url)
     await channel.send(embed=embed2)

def get_raw(Discord_id):
    url = 'api link'    
    myobj = {'Discord-ID': str(Discord_id)}
    x = requests.post(url, headers=myobj)
    z = x.text
    data = json.loads(str(z))
    y = data["message"]
    print(x.text)
    print(x.status_code)
    r=y['annoucement']
    print(y)
    print(r)
    return y

@client.command()  
async def see_raw_materials(ctx):#7 To see raw materials
    Discord_id = ctx.author.id
    x = get_raw(Discord_id)
    user=x["user"]
    embed = discord.Embed(title=" {} ".format(user),
                          color=0x00ffff,
                          timestamp=datetime.datetime.utcnow())
    embed.set_footer(text=f'Requested by {ctx.author.name}',
                     icon_url=ctx.author.avatar_url)
    await ctx.author.send(embed=embed)

def get_txn(Discord_id):
  url = 'api link'
  myobj = {'Discord-ID':str(Discord_id)}
  x = requests.post(url, headers = myobj)
  z = x.text
  data=json.loads(str(z))
  y= data["message"]
  print(x.text)
  print(x.status_code)
  return y

@client.command()#8 for transaction with raw bot
async def procure(ctx):
  Discord_id=ctx.author.id
  channel = client.get_channel(788034123100454952)
  x=get_txn(Discord_id)
  user=x["user"]
  embed=discord.Embed(title=user,color=0x00ffff, timestamp=datetime.datetime.utcnow())
  embed.set_footer(text=f'Requested by {ctx.author.name}', icon_url=ctx.author.avatar_url)
  await ctx.send(embed=embed)
  announce=x['annoucement']
  if announce != None:
     embed2 = discord.Embed(title=" {} ".format(announce),
                          color=0x00ffff,
                          timestamp=datetime.datetime.utcnow())
     embed2.set_footer(text=f'Requested by {ctx.author.name}',
                     icon_url=ctx.author.avatar_url)
     await channel.send(embed=embed2)

def get_update(Discord_id,bid):
   url = 'api link'
   myobj = {'Discord-ID':str(Discord_id)}
   d={"amount": bid }
   x = requests.post(url, headers = myobj,data=d)
   z = x.text
   data = json.loads(str(z))
   y = data["message"]
   print(x.text)
   print(x.status_code)
   r=y['annoucement']
   print(y)
   print(r)
   return y

@client.command()#9 for biding product price to the government
async def quote_bid(ctx,msg1):
  Discord_id = ctx.author.id
  channel = client.get_channel(788034123100454952)
  amount = msg1
  x = get_update(Discord_id,amount)
  user=x["user"]
  embed=discord.Embed(title=user,color=0x00ffff, timestamp=datetime.datetime.utcnow())
  embed.set_footer(text=f'Requested by {ctx.author.name}', icon_url=ctx.author.avatar_url)
  await ctx.send(embed=embed)
  announce=x['annoucement']
  if announce != None:
     embed2 = discord.Embed(title=" {} ".format(announce),
                          color=0x00ffff,
                          timestamp=datetime.datetime.utcnow())
     embed2.set_footer(text=f'Requested by {ctx.author.name}',
                     icon_url=ctx.author.avatar_url)
     await channel.send(embed=embed2)

def gcp(Discord_id):
   url = 'api link'  
   myobj = {'Discord-ID':str(Discord_id)}
   x = requests.post(url, headers = myobj)
   z = x.text
   data=json.loads(str(z))
   y= data["message"]
   print(x.text)
   print(x.status_code)
   return y

@client.command()#for update of company to know its status of coins and exp
async def get_current(ctx):
  Discord_id=ctx.author.id
  x=gcp(Discord_id)
  embed=discord.Embed(title=x,color=0x00ffff, timestamp=datetime.datetime.utcnow())
  embed.set_footer(text=f'Requested by {ctx.author.name}', icon_url=ctx.author.avatar_url)
  await ctx.send(embed=embed)

##BIDDING PHASE

def bid_item(Discord_ID):
    url = 'api link'
    myobj = {'Discord-ID': str(Discord_ID)}
    x = requests.post(url, headers=myobj)
    z = x.text
    data = json.loads(str(z))
    y = data["message"]
    print(x.text)
    print(x.status_code)
    return y
@client.command()  #10 bid on item
async def bid(ctx):
    Discord_id = ctx.author.id
    x = bid_item(Discord_id)
    embed = discord.Embed(title=" {} ".format(x),
                          color=0x00ffff,
                          timestamp=datetime.datetime.utcnow())
    embed.set_footer(text=f'Requested by {ctx.author.name}', icon_url=ctx.author.avatar_url)
    await ctx.author.send(embed=embed)

def abid(Discord_ID, pssword):
    url = 'api link'
    myobj = {'Discord-ID': str(Discord_ID), 'Password': pssword}
    x = requests.post(url, headers=myobj)
    z = x.text
    data = json.loads(str(z))
    y = data["message"]
    print(x.text)
    print(x.status_code)
    r=y['annoucement']
    print(y)
    print(r)
    return y


@client.command()  #11 announce bid
async def announce_bid(ctx, msg1):
    Discord_id = ctx.author.id
    password=msg1
    channel = client.get_channel(788034123100454952)
    x = abid(Discord_id,password)
    user=x["user"]
    embed = discord.Embed(title=" {} ".format(user),
                          color=0x00ffff,
                          timestamp=datetime.datetime.utcnow())
    embed.set_image(
        url='https://fedkiit.com/static/images/slider/Websitebanner.jpg')
    embed.set_footer(text=f'Requested by {ctx.author.name}',
                     icon_url=ctx.author.avatar_url)
    await ctx.author.send(embed=embed)
    announce=x['annoucement']
    if announce != None:
     embed2 = discord.Embed(title=" {} ".format(announce),
                          color=0x00ffff,
                          timestamp=datetime.datetime.utcnow())
     embed2.set_footer(text=f'Requested by {ctx.author.name}',
                     icon_url=ctx.author.avatar_url)
     await channel.send(embed=embed2)

def cbid(Discord_ID, pssword):
    url = 'api link'
    myobj = {'Discord-ID': str(Discord_ID), 'Password': pssword}
    x = requests.post(url, headers=myobj)
    z = x.text
    data = json.loads(str(z))
    y = data["message"]
    print(x.text)
    print(x.status_code)
    r=y['annoucement']
    print(y)
    print(r)
    return y


@client.command()  #12 close bid 
async def close_bid(ctx, msg1):
    Discord_id = ctx.author.id
    password=msg1
    channel = client.get_channel(788034123100454952)
    x = cbid(Discord_id,password)
    user=x["user"]
    embed = discord.Embed(title=" {} ".format(user),
                          color=0x00ffff,
                          timestamp=datetime.datetime.utcnow())
    embed.set_image(
        url='https://fedkiit.com/static/images/slider/Websitebanner.jpg')
    embed.set_footer(text=f'Requested by {ctx.author.name}',
                     icon_url=ctx.author.avatar_url)
    await ctx.author.send(embed=embed)
    announce=x['annoucement']
    if announce != None:
     embed2 = discord.Embed(title=" {} ".format(announce),
                          color=0x00ffff,
                          timestamp=datetime.datetime.utcnow())
     embed2.set_footer(text=f'Requested by {ctx.author.name}',
                     icon_url=ctx.author.avatar_url)
     await channel.send(embed=embed2)


##CORPORATE PHASE

def get_bank_account(Discord_ID):
    url = 'api link'
    myobj = {"Discord-ID": str(Discord_ID)}
    x = requests.post(url, headers=myobj)
    z = x.text
    data=json.loads(str(z))
    y= data["message"]
    print(x.text)
    print(x.status_code)
    return y

@client.command()  #13 get the account details
async def bal(ctx):
    Discord_id = ctx.author.id
    x = get_bank_account(Discord_id)
    embed = discord.Embed(
        title="Total Balance : {} ".format(x),
        color=0x00ffff,
        timestamp=datetime.datetime.utcnow())
    embed.set_image(
        url='https://fedkiit.com/static/images/slider/Websitebanner.jpg')
    embed.set_footer(
        text=f'Requested by {ctx.author.name}', icon_url=ctx.author.avatar_url)
    await ctx.author.send(embed=embed)

def con(Discord_id,XP):
    url = 'api link'
    myobj = {'Discord-ID': str(Discord_id)}
    da={"xp":XP}
    x = requests.post(url, headers=myobj,data=da)
    z = x.text
    data=json.loads(str(z))
    y= data["message"]
    print(x.text)
    print(x.status_code)
    return y


@client.command()  #14 for converting xp into coins
async def convert(ctx,msg1):
    Discord_id = ctx.author.id
    xp=msg1
    x = con(Discord_id,xp)
    embed = discord.Embed(
        title="{} ".format(x),
        color=0x00ffff,
        timestamp=datetime.datetime.utcnow())
    embed.set_footer(
        text=f'Requested by {ctx.author.name}', icon_url=ctx.author.avatar_url)
    await ctx.author.send(embed=embed)


def Op_list(Discord_id,password):
    url = 'api link'
    myobj = {
        'Discord-ID': str(Discord_id),
        'Password': password
    }
    x = requests.post(url, headers=myobj)
    print(x.status_code)
    print(x.json())
    return x.json()

@client.command()  #15 forms random pair
async def pair(ctx,msg1):
  password=msg1
  Discord_id = ctx.author.id
  x = Op_list(Discord_id,password)
  if not  x["success"]  :
     password=msg1
     channel = client.get_channel(788034123100454952)
     c=x["message"]
     user=c["user"]
     print(user)
     embed = discord.Embed(
        title="{}".format(user),
        color=0x00ffff,
        timestamp=datetime.datetime.utcnow())
     embed.set_footer(
        text=f'Requested by {ctx.author.name}', icon_url=ctx.author.avatar_url)
     await ctx.author.send(embed=embed)
     announce=c['annoucement']
     if announce != None:
      embed2 = discord.Embed(title=" {} ".format(announce),
                          color=0x00ffff,
                          timestamp=datetime.datetime.utcnow())
      embed2.set_footer(text=f'Requested by {ctx.author.name}',
                     icon_url=ctx.author.avatar_url)
      await channel.send(embed=embed2)
  else:
    channel = client.get_channel(788034123100454952)
    z=x["message"]
    admin=z["admin"]
    embed = discord.Embed(
        title="{}".format(admin),
        color=0x00ffff,
        timestamp=datetime.datetime.utcnow())
    embed.set_footer(
        text=f'Requested by {ctx.author.name}', icon_url=ctx.author.avatar_url)
    await ctx.author.send(embed=embed)
    announce=z['annoucement']
    if announce != None:
     embed2 = discord.Embed(title=" {} ".format(announce),
                          color=0x00ffff,
                          timestamp=datetime.datetime.utcnow())
     embed2.set_footer(text=f'Requested by {ctx.author.name}',
                     icon_url=ctx.author.avatar_url)
     await channel.send(embed=embed2)
    user=z['user']
    for dis,message in user.items():
      if not dis: 
        continue
      dis=int(dis)
      embed = discord.Embed(
        title="{}".format(message),
        color=0x00ffff,
        timestamp=datetime.datetime.utcnow())
      embed.set_footer(
        text=f'Requested by {ctx.author.name}', icon_url=ctx.author.avatar_url)
      await dis.send(embed=embed)

      


def List_teams(Discord_id,Team_Name):
    url = 'api link'
    myobj = {'Discord-ID': str(Discord_id),'team_name': Team_Name}
    x = requests.post(url, headers=myobj)
    z = x.text
    data=json.loads(str(z))
    y= data["message"]
    print(x.text)
    print(x.status_code)
    return y
@client.command()  #Opponent Details
async def opponent(ctx,msg1):
    Team_name=msg1
    Discord_id = ctx.author.id
    x = List_teams(Discord_id,Team_name)
    embed = discord.Embed(
        title="{}".format(x),
        color=0x00ffff,
        timestamp=datetime.datetime.utcnow())
    embed.set_footer(
        text=f'Requested by {ctx.author.name}', icon_url=ctx.author.avatar_url)
    await ctx.author.send(embed=embed)


def get_option( Discord_id,Option):
    url = 'api link'
    myobj = {'Discord-ID': str(Discord_id)}
    myob= {'option':Option}
    x = requests.post(url, headers=myobj,data=myob)
    z = x.text
    data = json.loads(str(z))
    y = data["message"]
    print(x.text)
    print(x.status_code)
    r=y['annoucement']
    print(y)
    print(r)
    return y


@client.command()  #give 3 options
async def power(ctx, msg1):
    user = await client.fetch_user(485793313442627604) #you can also just type the 
    await user.send("Hi")

keep_alive()
client.run(os.getenv('Token'))
