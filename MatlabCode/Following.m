
t1 = 0:0.6:35.4;
%actual movement
%hand
l1 = [170 162 153 147 137 128 118 112 105 99 94 89 84 80 76 73 66 62 58 55 50 44 39 36 33 33 37 39 48 55 60 65 70 75 80 85 90 93 97 100 103 105 108 110 113 120 125 130 133 137 142 145 148 151 155 157 160 163 166 170];
%car
l2 = [144 140 133 125 120 106 98 89 83 74 74 70 67 67 56 55 48 44 38 42 39 34 26 26 13 12 12 18 35 39 44 54 51 60 66 65 65 69 71 71 86 86 80 82 89 93 104 104 108 110 116 125 127 127 126 135 136 137 140 144];

% gap between hand and r 
gap = abs(l1-l2);

%change frame
l1 = abs(l1 - 170);
l2 = abs(l2 - 144);


figure(1)
hold on;

y = [l1,l2];

axis([0 35.4 min(y) max(y)]);

plot(t1,l1,'r');
plot(t1,l2,'b');

plot(t1,gap,'g');

line([0,35.4],[20,20]);


title('Distance following-the result of approaching/away from the car');
xlabel('Times(s)')
ylabel('Distance(mm)')
legend('Actual object movement','Actual car movement','gap between material and car','ideal gap','location',[0.35,0.04,0.74,0]);


average_gap = sum(gap)/60
rate = abs(average_gap-20)/average_gap * 100



