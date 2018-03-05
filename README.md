# COEN244

  03/05
Fixed the enum issue, include issue and string issue, not really sure about the cmake and idea issues, im still a super noob with git 

The way i did the "max number of rental days" is super not legit and ill find a better way to do it, probably make it a variable in carRentalmanagement instead of each Customer, would make it alot easier to modify them all at once too

What im trying to do is every Customer has a pointer to a Car, when a car is "rented" it just sets that pointer to a Car object.  The only thign im worried about is the deleting of a car or customer.  If car is deleted we'll need to shift all the other cars in the array and fix all the pointers since they'll now all be wrong.  Can you think of a better way to do things?
