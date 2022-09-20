# On_demand_traffic_light_control
This is an on-demand smart traffic light system for the embedded systems professional track by Egypt FWD and udacity. The main objective is to decrease waiting time for pedestrians as they have higher priority. The system has 2 modes: Normal mode, and pedestrian mode. In normal mode, the cars traffic light operates normally, and pedestrian traffic light are initially on red light on. Until the button is pressed, the system switches to pedestrian mode to allow pedestrians to cross the road safely and when the cycle is finished, the system switches back to normal mode.
- Normal mode:
1) (Phase_1) This mode starts with cars green light initially on and pedestrian red light (always) on.
2) (Phase_2) After 5 seconds, cars yellow light starts blinking for another 5 seconds while cars green light is still on.
3) (Phase_3) After the 5 seconds, cars green and yellow lights are turned off then cars red light is turned on for 5 seconds.
4) (Phase_4) The last phase, the yellow light starts blinking again for 5 seconds with cars red light is still on.
5) At last, the system goes back to phase_1 again.


- Pedestrian mode:

There is a special response for the pedestrian mode for every phase, depending on when the button is clicked.
1) If pressed in (phase_1) it skips green light remaining wait time and turns on car blinking yellow light, while cars green light is still on.
2) If pressed in (phase_2) it resets cars blinking yellow light remaining wait time and turns on pedestrians blinking yellow light.
3) if pressed in (phase_3) it resets cars red light remaining wait time, turns pedestrians green light on and red light off.
4) if pressed in (phase_4) it skips cars blinking yellow light remaining wait time and returns back to phase_2.
• Then, it turns back the program to (phase_2), reversing the flow of the cars light from (yellow to green) to (yellow to red) again.

- System flowchart

![System_flowchart_page-0001](https://user-images.githubusercontent.com/113522732/190506287-910849ae-55ac-4db3-8c99-278d44ac5d68.jpg)


- Simulation

https://user-images.githubusercontent.com/113522732/190509464-9cc47fe6-b68c-435f-b429-148ac13fa84d.mp4


