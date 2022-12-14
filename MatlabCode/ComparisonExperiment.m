%实验前后  垂直 平行 比较

t = 1:1:50;
%垂直

% 环境中未放入磁性物质 No magnetic substances are placed in the environment
N0x = [-0.03 -0.03 -0.02 -0.03 -0.05 -0.05 -0.02 -0.03 -0.02 -0.04 -0.02 -0.00 -0.01 -0.02 -0.03 -0.01 -0.03 -0.04 -0.08 -0.03 -0.06 -0.01 -0.01 -0.02 -0.04 -0.04 -0.04 -0.04 -0.03 -0.04 -0.04 -0.04 -0.03 -0.02 -0.01 -0.02 -0.02 -0.02 -0.03 -0.04 -0.01 -0.01 -0.04 -0.05 -0.01 -0.02 -0.05 -0.02 -0.01 -0.01 ]; 

% 实验结束后，从环境中移走磁性物质，再次测量此时的环境磁强度
% After the experiment, remove the magnetic substance from the environment,
% and measure the magnetic intensity of the environment at this time again.
N1x = [-0.04 -0.04 -0.03 -0.02 -0.03 -0.02 -0.04 -0.01 -0.03 -0.03 -0.02 -0.03 -0.02 -0.01 -0.01 -0.04 -0.04 -0.06 -0.05 -0.06 -0.05 -0.04 -0.02 -0.03 -0.04 -0.04 -0.03 -0.04 -0.06 -0.07 -0.06 -0.07 -0.06 -0.05 -0.06 -0.05 -0.03 -0.03 -0.03 -0.04 -0.04 -0.05 -0.05 -0.04 -0.04 -0.03 -0.04 -0.03 -0.04 -0.05  ];

x0 = [N0x,N1x];



%平行

% 环境中未放入磁性物质 No magnetic substances are placed in the environment
N2x= [0.03 0.03 0.01 -0.00 0.01 -0.00 -0.00 0.01 0.03 0.00 0.01 0.00 0.03 0.01 0.03 0.02 0.02 0.04 0.03 0.01 0.01 0.03 0.02 0.02 0.04 0.02 0.01 0.02 0.02 0.02 0.03 -0.01 -0.01 0.00 0.02 0.02 0.00 -0.01 0.02 0.01 0.02 0.04 0.01 0.04 0.05 0.03 -0.01 0.04 0.01 0.01 ]; 
N3x = [-0.04 -0.04 -0.03 -0.02 -0.03 -0.02 -0.04 -0.01 -0.03 -0.03 -0.02 -0.03 -0.02 -0.01 -0.01 -0.04 -0.04 -0.06 -0.05 -0.06 -0.05 -0.04 -0.02 -0.03 -0.04 -0.04 -0.03 -0.04 -0.06 -0.07 -0.06 -0.07 -0.06 -0.05 -0.06 -0.05 -0.03 -0.03 -0.03 -0.04 -0.04 -0.05 -0.05 -0.04 -0.04 -0.03 -0.04 -0.03 -0.04 -0.05  ];

x1 = [N2x,N3x];

figure(1)% the normal, before and after

subplot(1,2,1);

l1 = scatter(t,N0x,'red','filled'); % Environment magnetic strength before experiment 
hold on

l2 = scatter(t,N1x,'green','filled'); % Environment magnetic strength after experiment

line([1,50],[max(N0x),max(N0x)],'linestyle','--')
line([1,50],[min(N0x),min(N0x)],'linestyle','--')

line([1,50],[max(N1x),max(N1x)])
line([1,50],[min(N1x),min(N1x)])

axis([1 50 min(x0) max(x0)])
xlabel('Experiment times')
ylabel('Magnetic value')
legend('Environment magnetic strength before experiment','Environment magnetic strength after experiment');

hold off

title('Perpendicular Experiment')



%%%%%%%%%%%%%%%%%%

subplot(1,2,2);

l3 = scatter(t,N2x,'red','filled'); % Environment magnetic strength before experiment 
hold on

l4 = scatter(t,N3x,'green','filled'); % Environment magnetic strength after experiment

line([1,50],[max(N2x),max(N2x)],'linestyle','--')
line([1,50],[min(N2x),min(N2x)],'linestyle','--')

line([1,50],[max(N3x),max(N3x)])
line([1,50],[min(N3x),min(N3x)])

axis([1 50 min(x1) max(x1)])
xlabel('Experiment times')
ylabel('Magnetic value')


hold off

title('Parallel Experiment')


title_name = 'Comparison of Environmental Magnetic Value Before and After Experiment ';
sgtitle(title_name);
