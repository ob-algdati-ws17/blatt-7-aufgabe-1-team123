
    var chart_config = {
        chart: {
            container: "#collapsable-example",

            animateOnInit: true,
            
            node: {
                collapsable: true
            },
            animation: {
                nodeAnimation: "easeOutBounce",
                nodeSpeed: 700,
                connectorsAnimation: "bounce",
                connectorsSpeed: 700
            }
        },
        nodeStructure: {
            text: "5",
            children: [
                {
                    text: "4",
                    children: [
                        {
                            text: "2",
							children: [
							{},
							{
								text: "3",
								children: [
								{},
								{}
								]
							}
							]
                        },
						{}
                    ]
                },
                {
                    text: "9",
                    children: [
                        {
                            text: "7",
							children: [
							{
								text: "6",
								children: [
								{},
								{}
								]
							},
							{}
							]
						},
						{
							text: "11",
							children: [
							{
								text: "10",
								children: [
								{},
								{}
								]
							},
							{
								text: "12",
								children: [
								{},
								{}
								]
							}
							]
						}
                    ]
                }
            ]
        }
    };