# -*- coding: utf-8 -*-
"""
Created on Thu May 20 15:14:52 2021

@author: PC
"""

class Point2D:
    
    maxDistanceToOrigin=0
    def __init__(self,pX,pY):
        self.__x__=pX
        self.__y__=pY
        distanciaActual=(pX**2+pY**2)**0.5
        if distanciaActual>Point2D.maxDistanceToOrigin:
            Point2D.maxDistanceToOrigin=distanciaActual
            
    def __str__(self):
        return "["+str(self.__x__)+","+str(self.__y__)+"]"
   
    def getDistance(self,punto2):
        x=self.__x__-punto2.__x__
        y=self.__y__-punto2.__y__
        return (x**2+y**2)**0.5
    def getDistanceToOrigin(punto):
        return (punto.__x__**2+punto.__y__**2)**0.5 
    def add(self, punto2):
        return Point2D(self.__x__+punto2.__x__,self.__y__+punto2.__y__)
    def getX(self):
        return self.__x__
    def getY(self):
        return self.__y__

if __name__== "__main__":
    punto1=Point2D(2,2)
    print("Maxima distancia: "+str(Point2D.maxDistanceToOrigin))
    punto2=Point2D(2,5)
    print("Maxima distancia: "+str(Point2D.maxDistanceToOrigin))
    print(punto1.getDistance(punto2))
    punto3=punto1.add(punto2)
    print(punto3)
    print("Maxima distancia: "+str(Point2D.maxDistanceToOrigin))
    print(Point2D.getDistanceToOrigin(punto2))
    