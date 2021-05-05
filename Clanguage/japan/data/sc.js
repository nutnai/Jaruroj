var a = [5,"a", "i", "u", "e", "o"]
var k = [5, "ka", "ki", "ku", "ke", "ko"]
var s = [5, "sa", "si", "su", "se", "so"]
var t = [5, "ta", "ti", "tu", "te", "to"]
var na = [5, "na", "ni", "nu", "ne", "no"]
var h = [5, "ha", "hi", "hu", "he", "ho"]
var m = [5, "ma", "mi", "mu", "me", "mo"]
var y = [3, "ya", "yu", "yo"]
var r = [5, "ra", "ri", "ru", "re", "ro"]
var w = [2, "wa", "wo"]
var n = [1, "n"]

var g = [5, "ga", "gi", "gu", "ge", "go"]
var z = [5, "za", "zi", "zu", "ze", "zo"]
var d = [5, "da", "di", "du", "de", "do"]
var b = [5, "ba", "bi", "bu", "be", "bo"]
var p = [5, "pa", "pi", "pu", "pe", "po"]

var ky = [3, "kya", "kyu", "kyo"]
var gy = [3, "gya", "gyu", "gyo"]
var sh = [3, "sha", "shu", "sho"]
var j =  [3, "ja", "ju", "jo"]
var ch = [3, "cha", "chu", "cho"]
var ny = [3, "nya", "nyu", "nyo"]
var hy = [3, "hya", "hyu", "hyo"]
var by = [3, "bya", "byu", "byo"]
var my = [3, "mya", "myu", "myo"]
var py = [3, "pya", "pyu", "pyo"]
var ry = [3, "rya", "ryu", "ryo"]

function randombar(input) {
    return input[Math.floor(Math.random()*input[0] + 1)]
}
function randomall() {
    var all = [a,k,s,t,na,h,m,y,r,w,n,g,z,d,b,p,ky,gy,sh,j,ch,ny,hy,by,my,py,ry]
    return randombar(all[Math.floor(Math.random()*all.length)])
}
function convest_romaji_to_hiragana(input) /*เปลี่ยนโรมาจิเป็นฮิรางานะ*/{
    return wanakana.toHiragana(input)
}
function before3sec() {
    questions = 0
    before3secmax = 4
    gameMode = 0
    beforesec = 0
    startStopwatch()
}
function nextquestions() {
    if(questions < questionsmax){
        questions++
        return true
    }else{
        end()
        return false
    }
}
function play() {
    document.getElementById("gameMode").disabled = true
    if(needGameMode == 1){
        timeinput[0].disabled = true
        timeinput[1].disabled = true
        btst1.disabled = true
    }else if(needGameMode == 2 ){
        diffi2.disabled = true
        roundmax.disabled = true
        score = 0
        roundnow = 0
        btst2.disabled = true
        start2 = true
    }else if(needGameMode == 3){
        diffi2.disabled = true
        roundmax.disabled = true
        score = 0
        roundnow = 0
        btst3.disabled = true
        start2 = true
    }else if(needGameMode == 4){
        roundmax.disabled = true
        btst4.disabled = true
        start4 = true
        roundnow = 0
        score = 0
        input4.className = ""
        hide4.className = "disable"
    }
    
}
function end() {
    stopStopwatch()
    finish.play()
    document.getElementById("gameMode").disabled = false
    if(needGameMode == 1){
        timeinput[0].disabled = false
        timeinput[1].disabled = false
        btst1.disabled = false
    }else if(needGameMode ==2){
        diffi2.disabled = false
        roundmax.disabled = false
        roundmax.disabled = false
        diffi2.disabled = false
        start2 = true
        roundnow = 1
        btst2.disabled = false
        show.innerHTML =   (timeuse/maxround).toString() + " sec./word<br>Correct " + 
                            score.toString() + "/" + maxround.toString()
        for(var i=0; i<9; i++){
            select2[i].innerHTML = ""
        }
        console.log(score.toString() + "/" + maxround.toString())
    }else if(needGameMode == 3){
        diffi2.disabled = false
        roundmax.disabled = false
        roundmax.disabled = false
        diffi2.disabled = false
        start2 = true
        roundnow = 1
        btst3.disabled = false
        show.innerHTML =   (timeuse/maxround).toString() + " sec./word<br>Correct " + 
                            score.toString() + "/" + maxround.toString()
        for(var i=0; i<9; i++){
            select2[i].innerHTML = ""
        }
        console.log(score.toString() + "/" + maxround.toString())
    }else if(needGameMode == 4){
        roundmax.disabled = false
        btst4.disabled = false
        start4 = true
        show.innerHTML =   (timeuse/maxround).toString() + " sec./word<br>Correct " + 
                            score.toString() + "/" + maxround.toString()
    }
    
}
function randomMode2(diff) {
    data2 = Array()
    for(var i=0; i<diff; i++){
        while(true){
            var temp = randomall()
            var allow = true
            for(var j=0; j<data2.length; j++){
                if(data2[j] == temp){
                    allow = false
                    break
                }
            }
            if(allow){
                data2[i] = temp
                break
            }
        }
    }
    anschoice = Math.floor(Math.random()*data2.length) + 1
}

document.addEventListener('keydown', logKey);
function logKey(e) {
    var c = e.key
    if(!start4){
        if(c >= 'a' && c <= 'z' && false){
            input4.value += c
        }else if(c == "Backspace" && false){
            var st2 = ""
            var st1 = input4.value
            for(var i=0; i<st1.length-1; i++){
                st2 += st1[i]
            }
            input4.value = st2
        }else if(c == "Enter" && input4.value){
            run4()
            input4.value = ""
        }
    }
}


//allmode
var ping = new Audio("data/ping.mp3")
var finish = new Audio("data/finish.mp3")
var gameMode
var needGameMode
var beforesec
var before3secmax
var timeshow = document.getElementsByName("timeShow")
//nultiple use
var roundmax //แสดงผลบน html
var show //โชว์คำถาม html
var roundnow //จำนวนรอบตอนนี้
var maxround//จำนวนคำถามสูงสุด
var score//จำนวนคะแนนที่ตอบถูกตอนนี้
var anschoice//ตำแหน่งหรือคำ คำตอบที่ถูก
var timeuse//จำนวนวินาที เวลาที่ใช้

//mode1
var timeLimitPerRound
var timeinput
var questions
var questionsmax
var btst1

//mode2
var select2
var diffi2
var maxchoice2
var data2 = Array()
var start2
var btst2

//mode3
var btst3

//mode4
var btst4
var start4 = true
var input4
var hide4
var submit4

function click1() {
    document.getElementById("show1").innerHTML = randomall()
    ping.play()
    document.getElementById("ans").innerHTML = convest_romaji_to_hiragana(document.getElementById("show1").innerHTML)
}
function click2() {
    randomMode2(maxchoice2)
    var xxx
    var yyy
    var zzz = Array()
    if(gameMode == 2){
        xxx = data2[anschoice-1]
        yyy = convest_romaji_to_hiragana(data2[anschoice-1])
        for(var i=0; i<data2.length; i++){
            zzz[i] = convest_romaji_to_hiragana(data2[i])
        }
    }else{
        yyy = data2[anschoice-1]
        xxx = convest_romaji_to_hiragana(data2[anschoice-1])
        zzz = data2
    }
    console.log("No."+(roundnow).toString()+" Choice : "+zzz+"\n   question : "+xxx.toString()+"\n   ans : "+yyy.toString())
    if(gameMode == 2){
        show.innerHTML = data2[anschoice-1]
    }else{
        show.innerHTML = convest_romaji_to_hiragana(data2[anschoice-1])
    }
    
    for(var i=0; i<9; i++){
        if(i%2 == 0){
            if(i/2 < maxchoice2){
                if(gameMode == 2){
                    select2[i].innerHTML = convest_romaji_to_hiragana(data2[i/2])
                }else{
                    select2[i].innerHTML = data2[i/2]
                }
                
            }else{
                select2[i].innerHTML = ""
            }
        }else if(i < (maxchoice2*2) - 1){
            select2[i].innerHTML = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"
        }else{
            select2[i].innerHTML = ""
        }
    }
}
function click4() {
    anschoice = randomall()
    show.innerHTML = convest_romaji_to_hiragana(anschoice)
    console.log("No."+(roundnow).toString() + " questions : "+convest_romaji_to_hiragana(anschoice)+"\n   ans : "+anschoice.toString())
}
function run2(choice) {
    if(!start2){
        roundnow++
        ping.play()
        var xxx
        var yyy
        if(gameMode == 2){
            xxx = convest_romaji_to_hiragana(data2[choice-1])
        }else xxx= data2[choice-1]
        if(choice == anschoice && choice){
            score++
            yyy = "Y"
        }else yyy = "......"
        if(choice){
            console.log(yyy+" Your ans : "+xxx.toString())
        }else console.log("--------------------------------------------------------------")
        if(roundnow > maxround){
            end()
        }else click2()
    }
    
}
function run4() {
    if(!start4){
        roundnow++
        ping.play()
        var yyy
        submit4 = input4.value
        if(submit4 == anschoice){
            score++
            yyy = "Y"
        }else yyy = "....."
        if(roundnow == 1){
            console.log("--------------------------------------------------------------")
        }
            console.log(yyy + " Your ans id : "+submit4)
        if(roundnow > maxround){
            end()
        }else click4()
    }
}



function PlayMode1() {
    timeinput = document.getElementById("timeInput")
    btst1 = document.getElementById("btst1")
    timeLimitPerRound = timeinput[0].value
    questionsmax = timeinput[1].value
    timeLimitPerRound = parseInt(timeLimitPerRound)
    questionsmax = parseInt(questionsmax)
    if(Number.isInteger(timeLimitPerRound) && Number.isInteger(questionsmax)){
        needGameMode = 1
        play()
        before3sec()
    }else{
        var t = ""
        if(!Number.isInteger(timeLimitPerRound)){
            t+="Please enter time in number"
        }
        if(!Number.isInteger(questionsmax)){
            t+="\nPlease enter questions in number"
        }
        alert(t)
    }
}
function PlayMode2() {
    show = document.getElementById("show2")
    btst2 = document.getElementById("btst2")
    select2 = document.getElementById("select2").children
    diffi2 = document.getElementById("difficult")
    roundmax = document.getElementById("maxRound2")
    maxround = (roundmax.value==1?10:(roundmax.value==2?20:30))
    maxchoice2 = (diffi2.value==1?3:(diffi2.value==2?4:5))
    needGameMode = 2
    play()
    before3sec()
    
}
function PlayMode3() {
    show = document.getElementById("show2")
    btst3 = document.getElementById("gameMode3")
    select2 = document.getElementById("select2").children
    diffi2 = document.getElementById("difficult")
    roundmax = document.getElementById("maxRound2")
    maxround = (roundmax.value==1?10:(roundmax.value==2?20:30))
    maxchoice2 = (diffi2.value==1?3:(diffi2.value==2?4:5))
    needGameMode = 3
    play()
    before3sec()
}
function PlayMode4() {
    show = document.getElementById("show4")
    btst4 = document.getElementById("btst4")
    roundmax = document.getElementById("maxRound4")
    input4 = document.getElementById("input4")
    hide4 = document.getElementById("hide4")
    maxround = (roundmax.value==1?10:(roundmax.value==2?20:30))
    needGameMode = 4
    play()
    before3sec()
}
function selectMode() {
    var Mode = document.getElementById("gameMode").value
    var maxMode = document.getElementById("gameMode").childElementCount
    for(var i=1; i<=maxMode; i++){
        if(Mode == i){
            document.getElementById("gameMode" + i.toString()).className = ""
        }else{
            document.getElementById("gameMode" + i.toString()).className = "disable"
        }
    }
    switch (Mode) {
        case "2":
            document.getElementById("btst2").className = ""
            break;
        case "3":
            document.getElementById("gameMode2").className = ""
            document.getElementById("btst2").className = "disable"
            break;
        default:
            break;
    }
}



var elapsedTimeWhenPaused
var elapsedTimeIntervalRef
var startTime
function startStopwatch() {
    setStartTime();
    elapsedTimeIntervalRef = setInterval(() => {
        var t = timeAndDateHandling.getElapsedTime(startTime);
        if(gameMode){
            timeshow.forEach(x => {
                x.innerHTML = t
            });
        }else{
            timeshow.forEach(x => {
                x.innerHTML = "00:0" + t
            });
        }
    }, 1000);
}
function setStartTime() {
    if (elapsedTimeWhenPaused) {
        startTime = new Date();
        // Subtract the elapsed hours, minutes and seconds from the current date
        // To get correct elapsed time to resume from it
        startTime.setHours(startTime.getHours() - elapsedTimeWhenPaused.hours);
        startTime.setMinutes(startTime.getMinutes() - elapsedTimeWhenPaused.minutes);
        startTime.setSeconds(startTime.getSeconds() - elapsedTimeWhenPaused.seconds);
    } else {
        startTime = new Date();
    }
}
function stopStopwatch() {
    // Clear interval
    if (typeof elapsedTimeIntervalRef !== "undefined") {
        clearInterval(elapsedTimeIntervalRef);
        elapsedTimeIntervalRef = undefined;
    }
}
function resetStopwatch() {
    // Clear interval
    if (typeof elapsedTimeIntervalRef !== "undefined") {
        clearInterval(elapsedTimeIntervalRef);
        elapsedTimeIntervalRef = undefined;
    }

    // Reset elapsed time when paused object
    elapsedTimeWhenPaused = undefined

    // Reset elapsed time text
    startStopwatch()
}
var timeAndDateHandling = {
    getElapsedTime: function (startTime) {
        let endTime = new Date();
        let timeDiff = endTime.getTime() - startTime.getTime();
        timeDiff = timeDiff / 1000;
        let seconds = Math.floor(timeDiff % 60);
        let secondsAsString = seconds < 10 ? "0" + seconds : seconds + "";
        timeDiff = Math.floor(timeDiff / 60);
        let minutes = timeDiff % 60;
        let minutesAsString = minutes < 10 ? "0" + minutes : minutes + "";
        timeDiff = Math.floor(timeDiff / 60);
        let hours = timeDiff % 24;
        timeDiff = Math.floor(timeDiff / 24);
        let days = timeDiff;

        let totalHours = hours + (days * 24); // add days to hours
        let totalHoursAsString = totalHours < 10 ? "0" + totalHours : totalHours + "";

        timeuse = ((hours*360) + (minutes*60) + (seconds))
        switch (gameMode) {
            case 0:
                if(beforesec < 3){
                    ping.play()
                    beforesec++
                }else{
                    resetStopwatch()
                    finish.play()
                    gameMode = needGameMode
                    startTime = new Date()
                    timeAndDateHandling.getElapsedTime(startTime);
                }
                if(!gameMode){
                    return before3secmax - beforesec
                }else{
                    return "00:00"
                }
                break;
            case 1:
                if(seconds % timeLimitPerRound == 0){
                    if(nextquestions()){
                        click1()
                    }
                }
                break;
            case 2:
                if(start2){
                    start2 = false
                    run2(0)
                }
                break;
            case 3:
                if(start2){
                    start2 = false
                    run2(0)
                }
                break;
            case 4:
                if(start4){
                    start4 = false
                    submit4 = "skip"
                    run4()
                }
                break
            default:
                break;
        }
        if (totalHoursAsString === "00") {
            return minutesAsString + ":" + secondsAsString;
        } else {
            return totalHoursAsString + ":" + minutesAsString + ":" + secondsAsString;
        }
    }
}