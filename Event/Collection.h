typedef struct CollectionItem {
	struct CollectionItem* next;
	Event* data;
} CollectionItem;



typedef struct Collection {
	CollectionItem* head; 
} Collection;



Collection* createCollection()
{
	Collection* a = (Collection*) malloc(sizeof(Collection));
	a->head = NULL;
	return a;
}


void addEventToCollection(Event* event, Collection* collection)
{
	
	CollectionItem* item = (CollectionItem*) malloc(sizeof(CollectionItem));
	item->data = event;
	item->next = NULL;

	CollectionItem* last = collection->head;
	if(last == NULL)
	{
		collection->head = item;
	}
	else
	{
		while(last->next != NULL) 
		{
			last = last->next;
		}
		last->next=item;
	}
	
}

int numberOfItemsInList(Collection* collection)
{
	int count = 0;

	CollectionItem* last = collection->head;
	while(last != NULL) 
	{
			
		last = last->next;
		count++;
	}
	return count;
}

void prepopulateCollection(Collection* collections)
{
	Event* head1   = (Event*) malloc(sizeof(Event));
	strcpy(head1->cityName, "Madrid");
	head1->timestamp = 1232;
	head1->participants = 9;
	head1->isCool = 1;
	addEventToCollection(head1,collections);

	Event* head2   = (Event*) malloc(sizeof(Event));
	strcpy(head2->cityName, "London");
	head2->timestamp = 123;
	head2->participants = 12;
	head2->isCool = 1;
	addEventToCollection(head2,collections);

	Event* head3   = (Event*) malloc(sizeof(Event));
	strcpy(head3->cityName, "Paris");
	head3->timestamp = 12;
	head3->participants = 100;
	head3->isCool = 1;
	addEventToCollection(head3,collections);

	Event* head4   = (Event*) malloc(sizeof(Event));
	strcpy(head4->cityName, "Kiev");
	head4->timestamp = 1;
	head4->participants = 33;
	head4->isCool = 1;
	addEventToCollection(head4,collections);

	//Event* head5   = (Event*) malloc(sizeof(Event));
	//strcpy(head5->cityName, "Madrid");
	//head5->timestamp = 1232;
	//head5->participants = 9;
	//head5->isCool = 0;
	//addEventToCollection(head5,collections);

	//Event* head6   = (Event*) malloc(sizeof(Event));
	//strcpy(head6->cityName, "London");
	//head6->timestamp = 0;
	//head6->participants = 233;
	//head6->isCool = 0;
	//addEventToCollection(head6,collections);

	//Event* head7   = (Event*) malloc(sizeof(Event));
	//strcpy(head7->cityName, "Paris");
	//head7->timestamp = 12;
	//head7->participants = 100;
	//head7->isCool = 0;
	//addEventToCollection(head7,collections);

	//Event* head8   = (Event*) malloc(sizeof(Event));
	//strcpy(head8->cityName, "Kiev");
	//head8->timestamp = 102;
	//head8->participants = 33;
	//head8->isCool = 0;
	//addEventToCollection(head8,collections);
}

void freeCollection(Collection* collection)
{
	CollectionItem* viewCollection = collection->head;
	while( viewCollection!= NULL)
	{
		CollectionItem* saveItem = viewCollection;
		viewCollection=viewCollection->next;
		
		free(saveItem->data);
		free(saveItem);
	}
	free(collection);
}

CollectionItem* itemAtIndex(int index, Collection* collection)
{
	int count = numberOfItemsInList(collection);
	if(index>count)
	{
		return NULL;
	}
	else
	{
		CollectionItem* last = collection->head;
		for(count = 0; count != index-1; count++) 
		{
			last = last->next;
		}
		return last;
	}
}

void printItemAtIndexInCollection(int index, Collection* collection)
{
	CollectionItem* last = itemAtIndex(index, collection);
	if(last == NULL)
	{
		printf("ERROR! Index with such an event does not exist");
	}
	else
	{
		Event* first = last->data;
		char* str = eventDescription(first);
		printf("%s\n", str);
		free(str);
	}
}
