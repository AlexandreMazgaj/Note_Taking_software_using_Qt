# MojoHelpdesk Android Application

## Project environment + used Extensions

* [Android Studio](https://developer.android.com/studio/index.html)
* [Realm](https://realm.io/)
* [Lombok](https://projectlombok.org/)

## MojoHelpdesk API

* [Discoball](https://sites.google.com/a/metadot.com/discoball/software/mojo-helpdesk/api-v3?pli=1)

## Structure of the Application

### The sign in activity

The application starts with the SignInActivity. This activity is not finished at all, since the api doesn't support android application, there is no way to connect to the server with the app for the moment. The way it is done for the moment is by getting the informations of the user with his email using this url: <https://app.mojohelpdesk.com/api/v3/users/get_by_email?email=>. And then the app gets the accounts of this user, using the id received from the cloud, using this url: <https://app.mojohelpdesk.com/api/v3/helpdesk/list>.
A way to make a secure connection to the application would be to use OAuth2, so you need to discuss Ivaylo and Daniel to implement it on the MojoHelpdesk server.

### The ticket display activity

After connecting to the app, the user will arrive to the ticket display activity. This is the central part of the application. If you need to make any change to the way the ticket are displayed, go to the ticket\_list\_item.xml file. Since this activity is central in the application, a lot is happening in this activity:

* Display the tickets
* Change helpdesk
* Click on ticket to display the details

The tickets are displayed using a recycler view. To change helpdesk, I used the navigation drawer menu and a dropdown list, to display the different helpdesks of the user. The user can display different tickets by clicking on the bottom menu. One function is used to get the tickets from the cloud, and to manage its pages:

```Java
private void displayPageOfTicketsFromCloud(final Long userId, final String accessKey, final NetworkUtils.TypeOfTicket typeOfTicket, final int numberOfPage)
```

This function is used by the bottom menu on click listener to display the right tickets.
To improve the user experience, the TicketDisplayActivity uses two ways of saving and restoring its state. The first way is used when the phone is rotated, the state is saved by using the saveInstanceState. To save the state of the application when going to another activity, the application uses the sharedPreferences. Two functions are used to restore the state of the application:

* save the activity state
 ```Java
 private void saveActivityStateInSharedPreferences(final String nameOfAccount, final int id)
 ```
* restore the activity state
 ```Java
 private void restoreActivityStateFromSharedPreferences(SharedPreferences preferences)
 ```
In order to display the current helpdesk which the user is using, I used a dropdown list, defined by the adapter ExpandableListAdapter.
Three functions are used to manage the expandable listp:

* Preparing the list
 ```Java
 private void prepareListData()
 ```
* Update the list when clicked
 ```Java
 private void updateSubMenuList()
 ```
* Set the onClick listener
 ```Java
 private void setOnChildListenerOfExpandableList()
 ```

From the TicketDisplayActivity, the user can click on a ticket, which will bring him to the TicketDetailActivity. The click is handle by the function
 ```Java
 public void handle(Ticket t)
 ```
Which is declared in the TicketAdapter and defined in the TicketDisplayActivity.

### The ticket detail activity

After clicking on a ticket from the TicketDisplayActivity, the user will arrive to the TicketDetailActivity. This activity is composed of two fragments, a fragment to display the comments of the ticket and a fragment to display the details of the ticket (the description, the assignee, the person who created the ticket, etc...).
The ticket detail activity is the activity getting the agents from the cloud, unfortunately, for the moment, it gets all the agents of the helpdesk, every time the user clicks on a ticket (in the TicketDisplayActivity). This can and should be changed, so the app gets the agents only once and save them in the database.

#### CommentFragment

The comment fragment is used to get, display and send comments of a ticket. To get the comments of a ticket, the fragment calls the function:
 ```Java
 public void getCommentsOfTicket(final Long ticketId, final String accessKey)
 ```

To send the comment to the server, the fragment uses this function:
 ```Java
 private void sendCommentToTicket(final Long ticketId, final String accessKey, final String body, final String cc, final Long userId, final boolean isPrivate, final int time_spent, final boolean addFilesToEmail, final boolean sendUserNotification)
 ```

The user can refresh the comments, to get the new one by clicking on the refresh button in the action bar.

To be able to send more information with the comment, there is an activity called NewCommentActivity. Since this is a new activity, there are a lot of information sent to it via an intent. This activity is used to put the comment in private or add a carbon copy to the comment.

#### DescriptionFragment

The DescriptionFragment allows the user to assign tickets to himself or the other agents of the Helpdesk. The Description fragment should be re designed, it is not very beautiful. The layout of the list of agents that appears when the "Assign ticket" button is clicked can be changed in the file list_agent.xml.

### The models

All the models are based on the data received from the Mojohelpdesk API.
