# Smart Soldier Strap
 Made a smart Strap to be worn on the wrist which measures vital body parameters ( Heart Rate , Body Temp , SpO2 levels) , it tracks the soldier using GPS . The strap is also equipped with a wifi module , that works as a mesh when it has other strap nodes in vicinity to send data without using any external network( Without using GSM to transmit this data to the main computer), otherwise uses gsm to transmit this information to a cloud server from where it can be retrieved


Idea description 
Our device proposes a compact reliable and efficient wireless vitals monitoring system that measures all the vital parameters of the body and tracks the soldier’s location after a specified interval of time. This system is totally automated and all the individual soldier straps act as nodes of the Ad-hoc network. 
Various sensors are used at one node which are interface using a microcontroller and the node first tries to connect to a network  if it fails it transmit its data over the public network
The GPS module will be used to find the coordinates of the soldier and GSM/GPRS module will be used to connect to a WAN network / public network in case MANET topology cannot be followed ( i.e. When a particular node is out of range and cannot be clustered i.e. connected to a cluster Head.).
Our device will also include establishment of a secure connection using either LoRaWan technology of another form of Hardware encryption technique.Security parameters will also be checked during the transmission over Mobile networks.
The device will also feature an SOS functionality that will have the highest priority i.e when the SOS is triggered , all other constraints will be overridden and any possible route to the SINK ( Resource Monitoring Location ) will be established.
Approach:
A CH (cluster head) is selected (on the basis of energy + distance from sink), after that message to all other non-CH nodes in the field is sent. Based on signal strength of received signals, node selects its cluster and send back an acknowledge message.
Assume MANET as tree with vertices as nodes and their weight telling the energy left. Edges denoting the distance and weights indicating energy requirement for that path.
We can use reactive protocol where data is sent only in case of emergency rather than continuously bombing CH and sink with data.


Algorithm / Solution:
1. All the nodes are organised in a tree data structure, with the root node being CS, its child nodes as CH and rest of the nodes, being leaf nodes.All the nodes have a corresponding address.
2. The nodes send data ( location, energy and health parameters ) to the CH node which further transfers the data to CS node.
3. CS node acquires the complete data from all the CH nodes and forms a graph ( with rectangular coordinates from location )
4. The graph is divided into segments, according to area which divides the nodes in cluster. In this area, an auxiliary node is selected.
5. Average distance from all the nodes in cluster is calculated  to find the node which is at minimum distance from all the nodes in the area.
6. CH is then determined by two factors - minimum distance from all the nodes and energy of the node. We devise a weighted equation where we provide coefficients based on the priority to distance and energy.
7. This method is used to determine the new CH in the cluster. CS sends the command to the node to make it the new CH and all the nodes in the tree are reorganised to the new structure.
8. Jump to step 2. 
Technology stack:
1.	Soldier end 
a.	Controller : Arduino
b.	Sensor : 
i.	MAX30100 & SP02 (heart rate and blood saturation)
ii.	ESP 8266 ( handle communication)
iii.	GSM –GPRS/GPS module (for location and accessing public network)
iv.	LM35 sensor ( for temperature)
v.	Seebeck effect plate
2.	Observer
a.	Web based application to monitor the vitals of each node. 

Use Case:
 
Show stopper
-	Long range can be obtained by using LoRa Modulation technology but costs higher and is harder to implement ( utilising LoRaWAN protocol ).
-	To calculate the blood pressure , we need  data of the average pumping volume of the heart during those conditions in which the soldiers would live so that higher accuracy can be obtained in calculating the Blood Pressure indirectly from the heart rate and sp02 levels.
-	Security of the data being transmitted is a matter of concern , these wireless communications can be intercepted by a false node that can attack the complete network and transmit false information onto the chain.By false node we mean - a node that should not be a part of the network ( external agency - such as hackers / other country intelligence , etc…)
-	Limited power supply leads to lower sampling and transmission rates to increase the battery life of the strap, which inturn leads to slower response time by the concerned department (also introduces an interval time after which the data will be transmitted so as to decrease the power consumption.).
