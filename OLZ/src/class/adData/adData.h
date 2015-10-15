/*
 * adData.h
 *
 *  Created on: 15/10/2015
 *      Author: Nuno
 */

#ifndef OLZ_SRC_CLASS_ADDATA_ADDATA_H_
#define OLZ_SRC_CLASS_ADDATA_ADDATA_H_

#include "../advertisement/advertisement.h"
#include "../user/user.h"
#include<vector>
 class AdData
 {
 private:
	 vector<Advertisement> advertisements;
 public:
	 void removeAdvertisement(unsigned int id);
	 void addAdvertisement(Advertisement ad);

 };


#endif /* OLZ_SRC_CLASS_ADDATA_ADDATA_H_ */
