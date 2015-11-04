#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>

using namespace std;

namespace enums{
enum Category{
	Agriculture, Animals, BabyAndChildren, Fashion, Home, Job, Leisure,
	PhonesAndTablets, RealEstate, Services, Sports, Technology, Vehicles,
	Others
};

enum Condition{
	New, UsedAsNew, Functional, ForParts
};


}

using namespace enums;

/**
 * @brief See if validCategory is a valid category then changes the value of category
 *
 * @param isValidCategory to compare with the enums
 *
 * @return Returns true if is a valid category
 */
bool ValidCategory(string isValidCategory);

/**
 * @brief Changes a string to a category
 *
 * @param validCategory to transform in a category
 *
 * @return Returns one Category
 */
Category StringToCategory(string validCategory);

/**
 * @brief Changes a string to a category
 *
 * @param validCategory  to transform in a string
 *
 * @return Returns one string
 */
string CategoryToString(Category validCategory);

/**
 * @brief See if validCategory is a valid category then changes the value of category
 *
 * @param validCondition to compare with the enums
 *
 * @return Returns true if is a valid category
 */
bool ValidCondition(string isValidCondition);

/**
 * @brief Changes a string to a condition
 *
 * @param validCondition to transform in a condition
 *
 * @return Returns one condition
 */
Condition StringToCondition(string validCondition);
/**
 * @brief Changes a condition to a string
 *
 * @param validCondition  to transform in a string
 *
 * @return Returns one string
 */
string ConditionToString(Condition validCondition);

#endif
