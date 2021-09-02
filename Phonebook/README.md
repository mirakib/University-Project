# Phonebook Application in C

This is a console based Phonebook application buit in C as a part of my university project for course Algorithm.

This application is using .txt files for storing data. The file system concept I implemented is a linear data storage system in different files for different data types. For one single record, their data will store on different files based on their type and with the same position in each files. Other operation like deletion, modification will also follow same file system for data manipulation.

## The file system can be easily understood by the following diagram below

![Blank diagram](https://user-images.githubusercontent.com/45521827/131867447-f243d877-0382-49e8-8cae-82f3357f14f0.png)

## Now let demonstrate the project from beggining.

After running the project, you will get a menu like this.

<img width="550" alt="Menu" src="https://user-images.githubusercontent.com/45521827/131867908-a7cebcdb-ced1-425e-b12c-51f6a26eded5.PNG">

Now lets try these following operations. First lets try option 2. Which is for veiwing all the stored records.

For the case, when there is no record in the database or files.

<img width="550" alt="Empty view" src="https://user-images.githubusercontent.com/45521827/131874440-24bee183-717a-4687-b949-2b44e8d9589d.PNG">

Lets add a record in the database. By pressing 1 & selecting option Add new which lets you add record to the files.

<img width="500" alt="Record Added" src="https://user-images.githubusercontent.com/45521827/131876439-c2272dd7-4a3d-48d5-b66c-4b90aa548120.PNG">

By Entering 1, the operation will repeat again. And if you enter 2, then it will take you back to the menu.

Now after adding some records in the database or files.

<img width="486" alt="AddView" src="https://user-images.githubusercontent.com/45521827/131882825-cddd4f28-2fec-49d7-8a15-a49114fdf072.PNG">

Now as we see we have some record. Lets do some other operations. Lets search for some specific data we have in our files by clicking 5.

<img width="550" alt="Search" src="https://user-images.githubusercontent.com/45521827/131876992-630d1a08-c925-440e-ae2e-468b5981b456.PNG">

Searching can be done in four ways. Lets do those one by one.

Search by name. By pressing 1.

<img width="500" alt="SearchName" src="https://user-images.githubusercontent.com/45521827/131877505-5f0698d2-4c36-4511-b806-6dbd2bb860f6.PNG">

Search by Contact number. By pressing 2.

<img width="550" alt="SearchContact" src="https://user-images.githubusercontent.com/45521827/131877722-1c89b2e9-5048-4a82-900a-192e6f9094e8.PNG">

Search by Postal code. By pressing 3.

<img width="432" alt="SearchPostal" src="https://user-images.githubusercontent.com/45521827/131878625-79620edc-7cd1-4c13-8c65-465a2f109a52.PNG">

Search by Gender. By pressing 4.

<img width="465" alt="SearchGender" src="https://user-images.githubusercontent.com/45521827/131879823-00681a8b-8476-4b2d-b7ca-ac8b59d9287b.PNG">

Now lets delete some record from the list. By pressing 3 and selecting Delete operation.

<img width="485" alt="Delete" src="https://user-images.githubusercontent.com/45521827/131880074-e8f3a561-b776-448f-a252-b7c79552b2e3.PNG">

By Entering 1, the operation will repeat again. And if you enter 2, then it will take you back to the menu.

Now lets modify a record from the list. By pressing 4 and selecting Modify operation.

Note: Leave the unchanged which you don't want to change & only input new data for which you want to be changed.

<img width="500" alt="Modify" src="https://user-images.githubusercontent.com/45521827/131880862-06fd3299-1dd5-43cc-80fb-6cf0ebe6f645.PNG">

By Entering 1, the operation will repeat again. And if you enter 2, then it will take you back to the menu.

Lets see if the data has been changed successfuly or not by going back to menu and listing all records by pressing 2.

<img width="550" alt="ReviewModify" src="https://user-images.githubusercontent.com/45521827/131881633-df4aa905-2af9-47fd-8c5c-1ae60c1516cf.PNG">

Now enter 6 to exit from the console.
