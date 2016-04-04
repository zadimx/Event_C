void swap(Collection* collection, CollectionItem* left, CollectionItem* right)
{ 
	Event* temp;
	temp = left->data;
	left->data = right->data;
	right->data = temp;
}

bool compareByCityName(CollectionItem* left, CollectionItem* right)
{
	if(strcmp (left->data->cityName, right->data->cityName) == 0)
	{
		if(left->data->isCool == false)
		{
			return true;
		}
	}
	if(strcmp (left->data->cityName, right->data->cityName) > 0)
	{
		return true;
	}
	return false;
}

bool compareByTimestamp(CollectionItem* left, CollectionItem* right)
{
	if(left->data->timestamp == right->data->timestamp)
	{
		if(left->data->isCool == false)
		{
			return true;
		}
	}
	if(left->data->timestamp > right->data->timestamp)
	{
		return true;
	}
	return false;
}

bool compareByParticipantsCount(CollectionItem* left, CollectionItem* right)
{
	if(left->data->participants == right->data->participants)
	{
		if(left->data->isCool == false)
		{
			return true;
		}
	}
	if(left->data->participants > right->data->participants)
	{
		return true;
	}
	return false;
}



void sortCollectionByOption(Collection* collection, int option)
{
	int length = numberOfItemsInList(collection);
	for (int i = 0; i < length; i++) {
         for (int j = 1; j < length-i; j++) 
		 {
			 CollectionItem* left = itemAtIndex(j, collection);
			 CollectionItem* right = itemAtIndex(j+1, collection);
			 if (option == 1 && compareByCityName(left, right))
			 {
                 swap(collection, left, right);
             }
			 else if(option == 2 && compareByTimestamp(left, right))
			 {
				 swap(collection, left, right);
			 }
			 else if(option == 3 && compareByTimestamp(left, right))
			 {
				 swap(collection, left, right);
			 }
         }
     }
}

void printFoundEvents(Collection* collection, char in[100])
 {
   CollectionItem* tmp = (CollectionItem*) malloc(sizeof(CollectionItem));
   tmp=collection->head; 
  
  while(tmp)
   {
	   int numberInPut = atoi(in);
	   if(numberInPut == tmp->data->timestamp || numberInPut == tmp->data->participants)
	   {
		   printf("%s\n", eventDescription(tmp->data));
	   }
	   else if (strstr(tmp->data->cityName, in) != NULL)
       {
		  printf("%s\n", eventDescription(tmp->data));
	   }
	   tmp=tmp->next;
	}
 }