#include "adData.h"

void AdData::removeAdvertisement(unsigned int id)
{
	unsigned int i;
	for(i=0; i < advertisements.size(); i++)
		if (advertisements[i]->getId() == id)
			break;

	if(i != advertisements.size()){
		delete advertisements[i];
		advertisements.erase(advertisements.begin() + i);
	}
}

void AdData::addAdvertisement(Advertisement* ad){
	advertisements.push_back(ad);
}

vector<Advertisement*> AdData::searchForAds(string text){
	vector<Advertisement*> results;

	for(unsigned int i = 0; i < advertisements.size(); i++){
		if(advertisements[i]->searchForText(text))
			results.push_back(advertisements[i]);
	}

	return results;
}
