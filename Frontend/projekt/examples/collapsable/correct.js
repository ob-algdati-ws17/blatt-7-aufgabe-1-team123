{
        "chart": {
            "container": "#collapsable-example",

            "animateOnInit": true,
            
            "node": {
                "collapsable": true
            },
            "animation": {
                "nodeAnimation": "easeOutBounce",
                "nodeSpeed": 700,
                "connectorsAnimation": "bounce",
                "connectorsSpeed": 700
            }
        },
        "nodeStructure": {
            "text": "5",
			"balance": "0",
            "children": [
                {
                    "text": "4",
					"balance": "-1",
                    "children": [
                        {
                            "text": "2",
							"balance": "1",
							"children": [
							{},
							{
								"text": "3",
								"balance": "0",
								"children": [
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
                    "text": "9",
					"balance": "0",
                    "children": [
                        {
                            "text": "7",
							"balance": "-1",
							"children": [
							{
								"text": "6",
								"balance": "0",
								"children": [
								{},
								{}
								]
							},
							{}
							]
						},
						{
							"text": "11",
							"balance": "0",
							"children": [
							{
								"text": "10",
								"balance": "0",
								"children": [
								{},
								{}
								]
							},
							{
								"text": "12",
								"balance": "1",
								"children": [
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