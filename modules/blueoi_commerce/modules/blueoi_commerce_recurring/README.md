# About this module
This modules provides overrides and improvements to recurring order sites, 
such as those that used commerce_license_billing.

# Charging credit cards
Included are default rules configs and alters that prevent credit card charges
from being fired on non-production environments. 
  
Set the following site variables to match your production environment/server variables.

* blueoi_commerce_recurring_production_check_key: A key such as HTTP_HOST for $_SERVER variables that will be checked against the value below.
* blueoi_commerce_recurring_production_check_value: A value such as "example.com" that will be checked with the key above.

If these values match, the server will be considered to be running on production, so be sure they are unique enough for your environemnt. 

For Platform.sh you can use "PLATFORM_ENVIRONMENT" and "master"

# Requirements

For automated recurring billing to work, the following conditions must be met:
* Payment methods must have card on file support and a charge callback.
* The customer must have a valid and active default card on file.
* Cron jobs must be running.
* Renewals happen when a billing cycles "End" property is past due.
* For another recurring order to be generated, the license associated with the billing cycle must be active.
 
