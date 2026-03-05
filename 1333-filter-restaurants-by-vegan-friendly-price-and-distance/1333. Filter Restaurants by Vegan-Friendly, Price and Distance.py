class Solution:
 def filterRestaurants(s,r,v,p,d):
  return[i for i,a,b,c,e in sorted(r,key=lambda x:(-x[1],-x[0]))if b>=v and c<=p and e<=d]