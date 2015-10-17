/*
 * adData.cpp
 *
 *  Created on: 15/10/2015
 *      Author: Nuno
 */

#include "adData.h"

void AdData::removeAdvertisement(unsigned int id)
{
	unsigned int i;

	for(i=0;i<advertisements.size();i++)
	{
		if (advertisements.at(i).getId()==id)
			break;
	}

	if(i!=advertisements.size())
	{
		advertisements.erase(advertisements.begin()+i);
	}
}

void AdData::addAdvertisement(Advertisement ad)
{
	advertisements.push_back(ad);
}

vector<Advertisement*> AdData::searchForAds(string text){
	vector<Advertisement*> results;

	for(unsigned int i = 0; i < advertisements.size(); i++){
		if(advertisements[i].searchForText(text))
			results.push_back(&advertisements[i]);
	}

	return results;
}

