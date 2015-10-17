#ifndef ADDATA_H
#define ADDATA_H

#include "../advertisement/advertisement.h"
#include "../user/user.h"
#include<vector>
#include<string>

using namespace std;

 class AdData
 {
 private:
	 vector<Advertisement> advertisements;
 public:
	 void removeAdvertisement(unsigned int id);
	 void addAdvertisement(Advertisement ad);
	 vector<Advertisement*> searchForAds(string text); //still not sure what type of data to return
 };


#endif
