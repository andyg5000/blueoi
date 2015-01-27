This module provides a new line item type that allows you to add return line
items to an existing order.

Things to know:

1) The line item type is a product line item called "Return"

2) The line item contains all of the fields as a basic product line item

3) Quantity value is automatically saved as a negative integer so that reports
are accurate.

4) Unit price is automaticall saved as a negative integer so that reports are
accurate (even though negative quantity * negative price is positive).


