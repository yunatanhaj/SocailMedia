#include "Status.h"
 const string Status::getext()
{
	return this->text_m;
}
int Status::gethour()
{
	return this->hour_m;
}
Date* Status::getdate()
{
	return this->date_m;
}