// CannonShooter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MATRIX4D.h"
#include <vector>

#define PI 3.14159265


struct Ball
{
	VECTOR4D bPos0;
	VECTOR4D bPos;
	VECTOR4D bVel;

};
void Pos4Targets(vector <VECTOR4D> &Target) {
	for (int i = 0; i < 20; i++) {
		
		Target[i].x = 200;
		Target[i].y = 0;
		Target[i].z = -50 + (i * 5);

		
	}
}


int main()
{
	VECTOR4D Gravity = { 0.f, -9.8f, 0.f, 0.f };
	VECTOR4D Wind = { 0.f,0.f,-9.f,0.f };
	VECTOR4D Cannon = { 0.f,0.f,0.f,0.f };
	
	//vector <VECTOR4D> Targets[20];

	vector <VECTOR4D> Target;
	Target.resize(20);
	
	Pos4Targets(Target);


	bool Finished = false;
	int choise;
	Ball Bola;
	
	
	float xg = 0.f;
	float yg = 0.f;
	float timeCut = 0.01f;

	// choise 1: Aim
	// choise 2: Shoot
	// choise 3: Look for targets 
	// choise 4: End 
	while (!Finished) {
		cout << "cannon simulator" << endl <<
			"type 1 to aim" << endl <<
			"type 2 to shoot" << endl <<
			"type 3 to look for targets" << endl <<
			"type 4 to change time interval" << endl <<
			"type 9 to end" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1: 
			cout << "cuantos grados en XZ [horizontal]" << endl;
			cin >> xg;
			cout << "cuantos grados en YX [vertical]" << endl;
			cin >> yg;

			Cannon.z = sin(xg*PI / 180) * cos(yg*PI/180);
			Cannon.y = sin(yg*PI / 180);
			Cannon.x = cos(xg*PI / 180) * cos(yg*PI / 180);
			cout << "tu vector de cannon es" << Cannon << endl;

			break;
		case 2:
			// Elije magnitud
			float power;
			cout << "Velocidad Inicial?" << endl;
			cin >> power;
			// escribe magnitud
			Bola.bVel = Cannon * power;
			Bola.bPos = { 0,0,0,0 };
			
			while (Bola.bPos.y >= 0) {
				Bola.bPos0 = Bola.bPos;
				Bola.bPos = (Bola.bPos + Bola.bVel);

				if (Bola.bPos.y < 0) {

					// rayo contra plano
					// rayo contra triangulo
					// rayo contra caja
					// rayo contra esfera
					// triangulo contra triangulo
					// triangulo contra caja
					// triangulo contra esfera
					// caja contra caja
					// caja contra esfera
					// esfera contra esfera


					VECTOR4D H = Bola.bPos - Bola.bPos0;
					float angulo = atanf(H.y / sqrt(H.x*H.x + H.z*H.z));
					float h = Bola.bPos0.y / sin(angulo);
					float Magnitud = h / Magnity(H);

					H = H * Magnitud;
					Bola.bPos0 = Bola.bPos0 - H;

					if (Bola.bPos0.y <= 0.0001 && Bola.bPos0.y >= -0.0001) {
						Bola.bPos0.y = 0;
					}


					cout << Bola.bPos0 << "	Final" << endl;
					for (int i = 0; i < Target.size(); i++) {
						if (Magnity(Bola.bPos0 - Target[i]) <= 3 && Target[i].w != 1)  {
							cout << "HIT!" << endl;
							Target[i].w = 1;
							
						}
					}
				

					break;
					    
				}

				Bola.bVel = Bola.bVel + Gravity + (Wind/20);
				cout << Bola.bPos << endl;
			}

			break;

		case 3: 
			for (int i = 0; i < Target.size(); i++) {
				if(Target[i].w == 0)
				cout << Target[i] << endl;
			}
			break;
		case 4:
			cout << "Change time in float intervals" << endl;
			cin >> timeCut;
			break;
		case 9: 
			Finished = true;
			break;
		default:
			break;
		}
	}

    return 0;
}

