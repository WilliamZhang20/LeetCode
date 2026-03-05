class Solution:
 def filterRestaurants(s,r,v,p,d):
  return[i for i,s,f,m,k in sorted(r,key=lambda x:(-x[1],-x[0]))if f>=v and m<=p and k<=d]