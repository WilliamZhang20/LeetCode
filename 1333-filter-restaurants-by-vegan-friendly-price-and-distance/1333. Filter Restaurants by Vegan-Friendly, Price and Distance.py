class Solution:
 def filterRestaurants(s,r,v,p,d):
  r=[i for i in r if(v<1or i[2])and i[3]<=p and i[4]<=d];r.sort(key=lambda x:(-x[1],-x[0]));return[i[0]for i in r]