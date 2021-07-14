select person.FirstName, person.LastName, address.City, address.State from person full outer join address on person.PersonId = address.PersonId where person.firstname is not NULL;
