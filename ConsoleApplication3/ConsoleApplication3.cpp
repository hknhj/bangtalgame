#include<bangtal.h>
#include<stdio.h>

SceneID warehouse, livingroom, garret, workroom, door, bedroom, start, outside, ending1, ending2;
ObjectID box, box2, bbaru1, bbaru2, bbaru, bedL[5], doorL[5], garretL[5], livingL[5], wareL[5], outsideobject, end1, end2, attack,
workingL[5], button, letter, lighter, frame, pole, rock, key, box3, gate, gate2, gate3, doll1, scary, enter, pennywize;
SoundID bgm, children, scream, wood, man, clap, wind, grass, fight, hitwood, boxopen;
TimerID timer1;
bool power = true, handlighter = false, locked1 = true, locked2= true, locked3 = true, bbadda = true, move =false, show = true, show2=true, show3 = true, show4=true, show5=true;
int click=0, hit=0, touch=0, hit2=0, hit3=0;

ObjectID createObject(const char* filename, SceneID scene, int x, int y, bool shown) {

	ObjectID object = createObject(filename);
	locateObject(object, scene, x, y);
	if (shown) {
		showObject(object);
	}

	return object;
}


void mouseCallback(ObjectID object, int x, int y, MouseAction action) {

	if (object == button) {

		power = !power;
		if (power == true) {
			setSceneLight(livingroom, 1.0f);
		}
		else {
			setSceneLight(livingroom, 0.4f);
		}
		click += 1;
		if (click >= 15) {
			showObject(box);
		}
	}

	else if (object == bedL[0]) {
		enterScene(bedroom);
	}
	else if (object == bedL[1]) {
		enterScene(bedroom);
	}
	else if (object == bedL[2]) {
		enterScene(bedroom);
	}
	else if (object == bedL[3]) {
		enterScene(bedroom);
	}
	else if (object == bedL[4]) {
		enterScene(bedroom);
	}

	else if (object == doorL[0]) {
		enterScene(door);
	}
	else if (object == doorL[1]) {
		enterScene(door);
	}
	else if (object == doorL[2]) {
		enterScene(door);
	}
	else if (object == doorL[3]) {
		enterScene(door);
	}
	else if (object == doorL[4]) {
		enterScene(door);
	}

	else if (object == garretL[0]) {
		enterScene(garret);
	}
	else if (object == garretL[1]) {
		enterScene(garret);
	}
	else if (object == garretL[2]) {
		enterScene(garret);
	}
	else if (object == garretL[3]) {
		enterScene(garret);
	}
	else if (object == garretL[4]) {
		enterScene(garret);
	}


	else if (object == livingL[0]) {
		enterScene(livingroom);
	}
	else if (object == livingL[1]) {
		enterScene(livingroom);
	}
	else if (object == livingL[2]) {
		enterScene(livingroom);
	}
	else if (object == livingL[3]) {
		enterScene(livingroom);
	}
	else if (object == livingL[4]) {
		enterScene(livingroom);
	}


	else if (object == wareL[0]) {
		enterScene(warehouse);
	}
	else if (object == wareL[1]) {
		enterScene(warehouse);
	}
	else if (object == wareL[2]) {
		enterScene(warehouse);
	}
	else if (object == wareL[3]) {
		enterScene(warehouse);
	}
	else if (object == wareL[4]) {
		enterScene(warehouse);
	}


	else if (object == workingL[0]) {
		enterScene(workroom);
	}
	else if (object == workingL[1]) {
		enterScene(workroom);
	}
	else if (object == workingL[2]) {
		enterScene(workroom);
	}
	else if (object == workingL[3]) {
		enterScene(workroom);
	}
	else if (object == workingL[4]) {
		enterScene(workroom);
	}


	else if (object == letter) {
		showImageViewer("편지지.png");
		
		
		
		if (getHandObject() == lighter) {
			showImageViewer("편지지 글씨.png");
			show = false;

		}
		else if (getHandObject() != lighter) {
			showMessage("음...? 편지에 뭔가 묻어있네...?");
		   if (show == true) {
			playSound(children, false);
			show = false;
			doll1 = createObject("인형1.png", bedroom, 450, 80, true);
			scaleObject(doll1, 0.8f);
		}
		}
		
		
	}

	else if (object == doll1) {
	    hideObject(doll1);
		playSound(children, false);
	
	}
	else if (object == lighter) {
		pickObject(lighter);
		
	}

	else if (object == frame) {
		showImageViewer("액자문제.png");

		if (show2 == true) {
			playSound(scream, false);
			show2 = false;
		}
	}


	else if (object == box) {
		if (locked1 == true) {
			showKeypad("17593", box);
			
		}
		else if(locked1 == false && show5==true){
			pickObject(bbaru1);
			showMessage("빠루 반 쪽을 얻었다!");
			show5 = false;

		}
		else if (show5 == false && locked1 ==false) {
			showMessage("빈 상자다");
		}
	}


	else if (object == rock) {

		if (getHandObject() == pole) {
			locateObject(rock, livingroom, 170, 100);
			showObject(rock);
			move = true;
		}
		else {
			if (move == false) {
				showMessage("물리시간에 뭔가를 배운거같은데....뭐더라....?");
			}
		}
	}

	else if (object == pole) {
	pickObject(pole);
    }

	else if (object == key) {
	pickObject(key);
}

	else if (object == box2) {
		if (getHandObject() == key) {
			pickObject(bbaru2);
			if (locked2 == true) {
				showMessage("빠루 반 쪽을 얻었다!");
				playSound(boxopen, false);
				locked2 = false;
			}
		}
		else if (locked2 == false) {
			showMessage("빈 상자다");
		
	}
	
	else if (locked2 == true) {
		showMessage("열쇠가 필요해!");
	}
}

	else if (object == gate) {
		if (getHandObject() == bbaru) {
			hit += 1;
			playSound(hitwood);

			if (hit >= 12) {
				hideObject(gate);
				showObject(gate2);
				playSound(wood, false);
				showMessage("판때기를 부셨다! 문을 열고 나가자");
			}
		}
	    else {
		    showMessage("무언가를 들고 문을 여러번 쳐보자");
	    }
    }

	else if (object == enter) {
	enterScene(livingroom);
	showMessage("으윽.... 얼마나 기절해있던거지...\n어서 탈출하자....");
	playSound(bgm, true);
}

	else if (object == gate2) {
	showObject(gate3);
}

	else if (object == gate3) {
	enterScene(outside);
	showMessage("휴..... 탈출한건가?");
	stopSound(bgm);
	playSound(wind, true);
}

	else if (object == outsideobject) {
	hit2 += 1;
	if (hit2 == 1) {
	showMessage("(부스럭 부스럭)");
	playSound(grass);
	}
	else if (hit2 == 2) {
	showMessage("무슨소리지?");
	stopSound(grass);
	}
	else if (hit2 == 3) {
	setSceneImage(outside, "밖 페니.png");
	showMessage("??? : 잡히면 사지를 찢어 죽여주마\n(공격버튼을 클릭해서 가능한 빠르게 공격하자)");
	hideObject(outsideobject);
	showObject(attack);
	showTimer(timer1);
	startTimer(timer1);
		
	}
	else if (hit2 >= 3 && hit3 >= 40) {
		showMessage("이제 탈출이다!!!");
		enterScene(ending2);
		playSound(clap, false);
		stopSound(wind);
		
	}
	
	}

	else if (object == attack) {
	hit3 += 1;
	playSound(fight);
	if (hit3 >= 40) {
		stopTimer(timer1);
		showMessage("??? : 으윽...내가 당하다니...");
		hideObject(attack);
		hideTimer();
		setSceneImage(outside, "밖.png");
		showObject(outsideobject);
	}
}

	else if (object == end1 || end2) {
	endGame();
}
	
	

}

void timerCallback(TimerID timer) {
	if (timer == timer1) {
		showMessage("죽여주마 낄낄낄낄낄낄");
		playSound(man, false);
		enterScene(ending1);
		stopSound(wind);
	}
}

 
void objectCallback(ObjectID object, EventID event) {
	if (object == box) {
		showMessage("상자가 열렸다!");
		playSound(boxopen, false);
		locked1 = false;
	}
}


int main() {

	bgm = createSound("브금.mp3");

	playSound(bgm, true);

	hitwood = createSound("문 때리는 소리.mp3");

	boxopen = createSound("상자소리.mp3");

	wind = createSound("바람.mp3");

	grass = createSound("풀소리.mp3");

	fight = createSound("때리는 소리.mp3");

	man = createSound("남자비명.mp3");
	
	children = createSound("애기 웃음소리.mp3");

	scream = createSound("비명.mp3");

	wood = createSound("나무 떨어지는 소리.mp3");

	clap = createSound("박수소리.mp3");

	livingroom = createScene("거실", "거실.png");

	warehouse = createScene("창고", "창고.png");

	garret = createScene("다락방", "다락방.png");

	workroom = createScene("작업실", "작업실.png");

	door = createScene("현관", "닫힌 배경.png");

	bedroom = createScene("침실", "침실.png");

	start = createScene("start", "ESCAPE.png");

	outside = createScene("밖", "밖.png");

	ending1 = createScene("배드엔딩", "배드엔딩.png");

	ending2 = createScene("해피엔딩", "성공.jpg");

	timer1 = createTimer(8.5f);

	end1 = createObject("END.png", ending1, 515, 70, true);
	scaleObject(end1, 0.5f);

	end2 = createObject("END.png", ending2, 515, 70, true);
	scaleObject(end2, 0.5f);

	outsideobject = createObject("밖.png", outside, 153, 70, true);

	pennywize = createObject("페니와이즈.png", outside, 500, 50, false);
	scaleObject(pennywize, 1.3f);

	attack = createObject("공격.png", outside, 1070, 100, false);
	scaleObject(attack, 0.3f);

	enter = createObject("enter.png", start, 503, 100, true);

	gate = createObject("닫힌 문.png", door, 420, 21, true);

	gate2 = createObject("민문.png", door, 393, 40, false);

	gate3 = createObject("열린문.png", door, 404, 35, false);


	bbaru1 = createObject("빠루 위.png");
	bbaru2 = createObject("빠루 아래.png");
	bbaru = createObject("빠루.png");


	bedL[0] = createObject("bedroom.png", livingroom, 200, 0, true);
    doorL[0] = createObject("door.png", livingroom, 357, 0, true);
	garretL[0] = createObject("garret.png", livingroom, 460, 0, true);
	wareL[0] = createObject("warehouse.png", livingroom, 762, 0, true);
	workingL[0] = createObject("working room.png", livingroom, 937, 0, true);
	button = createObject("배경없는버튼.png", livingroom, 450, 380, true);
	key = createObject("열쇠.png", livingroom, 340, 160, true);
	scaleObject(key, 0.1f);
	rock = createObject("돌.png", livingroom, 300, 100, true);
	scaleObject(rock, 0.5f);
	

	bedL[1] = createObject("bedroom.png", warehouse, 200, 0, true);
	doorL[1] = createObject("door.png", warehouse, 357, 0, true);
	garretL[1] = createObject("garret.png", warehouse, 460, 0, true);
	livingL[0] = createObject("livingroom.png", warehouse, 588, 0, true);
	workingL[1] = createObject("working room.png", warehouse, 937, 0, true);
	pole = createObject("장대.png", warehouse, 815, 200, true);
	scaleObject(pole, 0.5f);


	bedL[2] = createObject("bedroom.png", garret, 200, 0, true);
	doorL[2] = createObject("door.png", garret, 357, 0, true);
	livingL[1] = createObject("livingroom.png", garret, 588, 0, true);
	wareL[1] = createObject("warehouse.png", garret, 762, 0, true);
	workingL[2] = createObject("working room.png", garret, 937, 0, true);
	box = createObject("상자.png", garret, 440, 200, false);
	scaleObject(button, 0.08f);
	frame = createObject("액자.png", garret, 530, 350, true);
	scaleObject(frame, 0.25f);


	bedL[3] = createObject("bedroom.png", workroom, 200, 0, true);
	doorL[3] = createObject("door.png", workroom, 357, 0, true);
	garretL[2] = createObject("garret.png", workroom, 460, 0, true);
	livingL[2] = createObject("livingroom.png", workroom, 588, 0, true);
	wareL[2] = createObject("warehouse.png", workroom, 762, 0, true);
	lighter = createObject("라이터.png", workroom, 530, 280, true);
	scaleObject(lighter, 0.13f);
	box2 = createObject("상자2.png", workroom, 380, 220, true);
	scaleObject(box2, 0.2f);
	

	doorL[4] = createObject("door.png", bedroom, 357, 0, true);
	garretL[3] = createObject("garret.png", bedroom, 460, 0, true);
	livingL[3] = createObject("livingroom.png", bedroom, 588, 0, true);
	wareL[3] = createObject("warehouse.png", bedroom, 762, 0, true);
	workingL[3] = createObject("working room.png", bedroom, 937, 0, true);
	letter = createObject("편지.png", bedroom, 550, 270, true);
	scaleObject(letter, 0.3f);


	bedL[4] = createObject("bedroom.png", door, 200, 0, true);
	garretL[4] = createObject("garret.png", door, 460, 0, true);
	livingL[4] = createObject("livingroom.png", door, 588, 0, true);
	wareL[4] = createObject("warehouse.png", door, 762, 0, true);
	workingL[4] = createObject("working room.png", door, 937, 0, true);
	

	setObjectCallback(objectCallback);

	setTimerCallback(timerCallback);
	
	defineCombination(bbaru1, bbaru2, bbaru);

	setMouseCallback(mouseCallback);
	
	startGame(start);
	
}