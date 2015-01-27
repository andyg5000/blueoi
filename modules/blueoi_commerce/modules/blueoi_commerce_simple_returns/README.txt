This module provides a new line item type that allows you to add return line
items to an existing order. It's expected that the original line items will
remain on the order and the negative values of this line item will offset both
the quantity sold and the order balance.

==================

Things to know:

1) The line item type is a product line item called "Return"

2) The line item contains all of the fields as a basic product line item

3) Quantity value is automatically saved as a negative integer so that reports
are accurate.

4) Unit price is automaticall saved as a negative integer so that reports are
accurate (even though negative quantity * negative price is positive).

5) There is currently no validation to compare return with product line items
on the order.

6) Make sure to add this line item type to any reports that are calculating
product sales. The negative values of unit price and quantity will offset the
values properly.

7) If any reports, views, etc... are calulating values using unit price *
quantity, the values will be incorrect.

==================

How to use:

1) Load the admin order interface for any order.

2) Select "Return" as the line item type and click "Add line item"

3) Enter the SKU and the unit price (postive unit price will be save as a
negative automatically).

4) Save the order.
