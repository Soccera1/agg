<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Agg Math Game</title>
    <style>
        body {
            font-family: monospace;
            background: #000;
            color: #0f0;
            padding: 20px;
            line-height: 1.4;
        }
        .container {
            max-width: 800px;
            margin: 0 auto;
        }
        input {
            background: #000;
            color: #0f0;
            border: 1px solid #0f0;
            padding: 5px;
            font-family: monospace;
            margin: 5px 0;
        }
        button {
            background: #000;
            color: #0f0;
            border: 1px solid #0f0;
            padding: 10px 20px;
            font-family: monospace;
            cursor: pointer;
            margin: 5px;
        }
        button:hover {
            background: #0f0;
            color: #000;
        }
        .output {
            white-space: pre-line;
            margin: 10px 0;
        }
        .input-group {
            margin: 10px 0;
        }
    </style>
</head>
<body>
    <div class="container">
        <div id="output" class="output"></div>
        <div id="input-area" class="input-group"></div>
    </div>

    <script>
        // Global variables to maintain state
        let currentStep = 0;
        let tutorial = false;
        let accuracytype = 0;
        let playtime = 0;
        let number_length = 0;
        let end_time = 0;
        let score = 0;
        let questioncount = 0;
        let currentResult = 0;
        let gameRunning = false;
        let gameInterval;

        function print(text) {
            document.getElementById('output').innerHTML += text + '\n';
        }

        function clearInput() {
            document.getElementById('input-area').innerHTML = '';
        }

        function createInput(placeholder, callback) {
            const inputArea = document.getElementById('input-area');
            const input = document.createElement('input');
            input.type = 'text';
            input.placeholder = placeholder;
            input.addEventListener('keypress', function(e) {
                if (e.key === 'Enter') {
                    const value = input.value;
                    callback(value);
                }
            });
            inputArea.appendChild(input);
            input.focus();
        }

        function getUsername() {
            // Browser equivalent of getenv("USER")
            return "Player";
        }

        function randMod(max) {
            return Math.floor(Math.random() * max);
        }

        function time() {
            return Math.floor(Date.now() / 1000);
        }

        function startGame() {
            const username = getUsername();
            print(`Hello ${username}!`);
            print("This is a game written for AgnoxGD.");
            print("Would you like to see a tutorial");
            print("Type 1 for no, or 0 for yes.");
            
            createInput("Enter 0 or 1", function(input) {
                const tempInput = parseInt(input);
                if (!isNaN(tempInput)) {
                    tutorial = tempInput;
                }
                
                clearInput();
                
                if (tutorial) {
                    print("OK! Lets continue.");
                } else {
                    print("Welcome to Agg! This game tests your math skills against the clock.\n\nHow to Play:\n\n1.  Set Your Playtime: First, you'll decide how long you want to play by entering a duration in seconds.\n2.  Solve Math Problems: Once the game starts, you'll be presented with a series of random math problems: addition, division, subtraction, and multiplication. Your goal is to solve as many as you can before time runs out.\n3.  Enter Your Answer: After each problem, type your answer and press Enter. The game will immediately tell you if you're correct or incorrect.\n4.  Rack Up Points: For every correct answer, you'll earn a point. Your score will be tallied at the end.\n5.  Time's Up! The game ends automatically when your chosen playtime runs out. Good luck, and have fun!");
                }
                
                askAccuracyType();
            });
        }

        function askAccuracyType() {
            print("Would you like your accuracy as a float or as an int? Type 0 for float or 1 for int.");
            createInput("Enter 0 or 1", function(input) {
                accuracytype = parseInt(input);
                clearInput();
                askPlaytime();
            });
        }

        function askPlaytime() {
            print("\nHow long would you like to play for? Answer in seconds.");
            createInput("Enter seconds", function(input) {
                playtime = parseInt(input);
                clearInput();
                askNumberLength();
            });
        }

        function askNumberLength() {
            print("Please enter maximum possible number");
            createInput("Enter max number", function(input) {
                number_length = parseInt(input);
                clearInput();
                startGameLoop();
            });
        }

        function startGameLoop() {
            const unix_time = time();
            end_time = unix_time + playtime;
            score = 0;
            questioncount = 0;
            gameRunning = true;
            
            nextQuestion();
        }

        function nextQuestion() {
            const unix_time = time();
            
            if (unix_time >= end_time) {
                endGame();
                return;
            }
            
            const num1 = randMod(number_length) + 1;
            const num2 = randMod(number_length) + 1;
            const type = randMod(4) + 1;
            let result;
            
            if (type == 1) {
                print(`Add ${num1} and ${num2}`);
                result = num1 + num2;
            } else if (type == 2) {
                print(`Divide ${num1} by ${num2}`);
                result = num1 / num2;
            } else if (type == 3) {
                print(`Subtract ${num1} from ${num2}`);
                result = num2 - num1;
            } else if (type == 4) {
                print(`Multiply ${num1} by ${num2}`);
                result = num1 * num2;
            }
            
            currentResult = result;
            questioncount++;
            
            createInput("Enter your answer", function(entered) {
                let valid = 1;
                for (let i = 0; i < entered.length; i++) {
                    const char = entered[i];
                    if (!'0123456789.'.includes(char)) {
                        valid = 0;
                        break;
                    }
                }
                
                if (valid == 1) {
                    const answer = parseFloat(entered);
                    
                    if (currentResult == answer) {
                        print("Correct!");
                        score++;
                    } else {
                        print(`Incorrect! The correct answer is ${currentResult}.`);
                    }
                } else {
                    print("Error! An invalid character was entered.");
                    endGame();
                    return;
                }
                
                clearInput();
                setTimeout(nextQuestion, 100); // Small delay to prevent blocking
            });
        }

        function endGame() {
            gameRunning = false;
            const username = getUsername();
            
            const accuracy = score / questioncount * 100;
            
            print(`Your score is ${score}!`);
            if (score >= 1) {
                print(`Great job, ${username}!`);
            } else {
                print(`Try again!, ${username}.`);
            }
            
            if (accuracytype == 1) {
                print(`You got an accuracy of ${Math.floor(accuracy)}%!`);
            } else {
                print(`You got an accuracy of ${accuracy}%!`);
            }
        }

        // Start the game when page loads
        window.onload = function() {
            startGame();
        };
    </script>
</body>
</html>
