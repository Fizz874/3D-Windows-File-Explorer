#include "TextComposer.h"
#include <vector>
#include <TextComposerData.h>



int vcount = 0;

int TextComposer::Compose()
{
	vertices0.clear();

	normals.clear();
	coords.clear();
	vcount = 0;
	const float xspace = 20;
	float x = 0;

	std::vector<char> data(_text.begin(), _text.end());
	reverse(data.begin(), data.end());
	for (int i = 0; i < data.size(); i++)
	{
		switch (data[i])
		{
		case '1':
			x += AddChar(NUM1_DATA, NUM1_VCount, x );
			vcount += NUM1_VCount;
			break;
		case '2':
			x += AddChar(NUM2_DATA, NUM2_VCount, x );
			vcount += NUM2_VCount;
			break;
		case '3':
			x += AddChar(NUM3_DATA, NUM3_VCount, x);
			vcount += NUM3_VCount;
			break;
		case '4':
			x += AddChar(NUM4_DATA, NUM4_VCount, x);
			vcount += NUM4_VCount;
			break;
		case '5':
			x += AddChar(NUM5_DATA, NUM5_VCount, x);
			vcount += NUM5_VCount;
			break;
		case '6':
			x += AddChar(NUM6_DATA, NUM6_VCount, x);
			vcount += NUM6_VCount;
			break;
		case '7':
			x += AddChar(NUM7_DATA, NUM7_VCount, x);
			vcount += NUM7_VCount;
			break;
		case '8':
			x += AddChar(NUM8_DATA, NUM8_VCount, x);
			vcount += NUM8_VCount;
			break;
		case '9':
			x += AddChar(NUM9_DATA, NUM9_VCount, x);
			vcount += NUM9_VCount;
			break;
		case '0':
			x += AddChar(NUM0_DATA, NUM0_VCount, x);
			vcount += NUM0_VCount;
			break;

		case 'A':
		case 'a':
		case '¹':
			x += AddChar(A_DATA, A_VCount, x);
			vcount += A_VCount;
			break;
		case 'B':
		case 'b':
			x += AddChar(B_DATA, B_VCount, x);
			vcount += B_VCount;
			break;
		case 'C':
		case 'c':
		case 'æ':
			x += AddChar(C_DATA, C_VCount, x);
			vcount += C_VCount;
			break;

		case 'D':
		case 'd':
			x += AddChar(D_DATA, D_VCount, x);
			vcount += D_VCount;
			break;

		case 'E':
		case 'e':
		case 'ê':
			x += AddChar(E_DATA, E_VCount, x);
			vcount += E_VCount;
			break;

		case 'F':
		case 'f':
			x += AddChar(F_DATA, F_VCount, x);
			vcount += F_VCount;
			break;

		case 'G':
		case 'g':
			x += AddChar(G_DATA, G_VCount, x);
			vcount += G_VCount;
			break;

		case 'H':
		case 'h':
			x += AddChar(H_DATA, H_VCount, x);
			vcount += H_VCount;
			break;

		case 'I':
		case 'i':
			x += AddChar(I_DATA, I_VCount, x);
			vcount += I_VCount;
			break;

		case 'J':
		case 'j':
			x += AddChar(J_DATA, J_VCount, x);
			vcount += J_VCount;
			break;

		case 'K':
		case 'k':
			x += AddChar(K_DATA, K_VCount, x);
			vcount += K_VCount;
			break;

		case 'L':
		case 'l':
		case '³':
			x += AddChar(L_DATA, L_VCount, x);
			vcount += L_VCount;
			break;

		case 'M':
		case 'm':
			x += AddChar(M_DATA, M_VCount, x);
			vcount += M_VCount;
			break;

		case 'N':
		case 'n':
		case 'ñ':
			x += AddChar(N_DATA, N_VCount, x);
			vcount += N_VCount;
			break;

		case 'O':
		case 'o':
		case 'ó':
			x += AddChar(O_DATA, O_VCount, x);
			vcount += O_VCount;
			break;

		case 'P':
		case 'p':
			x += AddChar(P_DATA, P_VCount, x);
			vcount += P_VCount;
			break;

		case 'R':
		case 'r':
			x += AddChar(R_DATA, R_VCount, x);
			vcount += R_VCount;
			break;

		case 'S':
		case 's':
		case 'œ':
			x += AddChar(S_DATA, S_VCount, x);
			vcount += S_VCount;
			break;

		case 'T':
		case 't':
			x += AddChar(T_DATA, T_VCount, x);
			vcount += T_VCount;
			break;

		case 'U':
		case 'u':
			x += AddChar(U_DATA, U_VCount, x);
			vcount += U_VCount;
			break;

		case 'V':
		case 'v':
			x += AddChar(V_DATA, V_VCount, x);
			vcount += V_VCount;
			break;

		case 'W':
		case 'w':
			x += AddChar(W_DATA, W_VCount, x);
			vcount += W_VCount;
			break;

		case 'X':
		case 'x':
			x += AddChar(X_DATA, X_VCount, x);
			vcount += X_VCount;
			break;

		case 'Y':
		case 'y':
			x += AddChar(Y_DATA, Y_VCount, x);
			vcount += Y_VCount;
			break;

		case 'Z':
		case 'z':
		case '¿':
		case 'Ÿ':
			x += AddChar(Z_DATA, Z_VCount, x);
			vcount += Z_VCount;
			break;

		case '+':
			x += AddChar(PLUS_DATA, PLUS_VCount, x);
			vcount += PLUS_VCount;
			break;

		case '-':
			x += AddChar(MINUS_DATA, MINUS_VCount, x);
			vcount += MINUS_VCount;
			break;

		case '_':
			x += AddChar(UNDER_DATA, UNDER_VCount, x);
			vcount += UNDER_VCount;
			break;

		case '=':
			x += AddChar(EQUAL_DATA, EQUAL_VCount, x);
			vcount += EQUAL_VCount;
			break;

		case ':':
			x += AddChar(DDOT_DATA, DDOT_VCount, x);
			vcount += DDOT_VCount;
			break;

		case ';':
			x += AddChar(SCOLON_DATA, SCOLON_VCount, x);
			vcount += SCOLON_VCount;
			break;

		case '.':
			x += AddChar(DOT_DATA, DOT_VCount, x);
			vcount += DOT_VCount;
			break;

		case ',':
			x += AddChar(COMMA_DATA, COMMA_VCount, x);
			vcount += COMMA_VCount;
			break;

		case '"':
			x += AddChar(DQUOTE_DATA, DQUOTE_VCount, x);
			vcount += DQUOTE_VCount;
			break;

		case '\'':
			x += AddChar(QUOTE_DATA, QUOTE_VCount, x);
			vcount += QUOTE_VCount;
			break;

		case '\\':
			x += AddChar(BSLASH_DATA, BSLASH_VCount, x);
			vcount += BSLASH_VCount;
			break;

		case '/':
			x += AddChar(SLASH_DATA, SLASH_VCount, x);
			vcount += SLASH_VCount;
			break;

		case '(':
			x += AddChar(BRACKETL_DATA, BRACKETL_VCount, x);
			vcount += BRACKETL_VCount;
			break;

		case ')':
			x += AddChar(BRACKETR_DATA, BRACKETR_VCount, x);
			vcount += BRACKETR_VCount;
			break;
		case '!':
			x += AddChar(EXCL_DATA, EXCL_VCount, x);
			vcount += EXCL_VCount;
			break;
		case ' ':
			x += xspace;
			break;
		default:
			break;
		}
		x += xspace;
	}
	_vertices0 = new float[vertices0.size()];
	copy(vertices0.begin(), vertices0.end(), _vertices0);


	//vertex normals
	for (int i = 0; i < vcount; i++) //
	{
		normals.push_back(0);
		normals.push_back(0);
		normals.push_back(-1);
		normals.push_back(0);
	}
	_normals = new float[normals.size()];
	copy(normals.begin(), normals.end(), _normals);
	//texture coords
	float texSeq[12] = { 0,0, 0,1, 1,1, 0,0, 1,1, 1,0 };
	int index = 0;
	for (int i = 0; i < vcount * 2; i++) 
	{
		coords.push_back(texSeq[index++]);
		if (index == 12) index = 0;
	}
	_coords = new float[coords.size()];
	copy(coords.begin(), coords.end(), _coords);

	_vertexCount = vcount;
	_width = x;
	return 0;
}

float TextComposer::AddChar(float* vData, int vCount, float x)
{
	int pos = 0;
	int maxw = 0;

	for (int i = 0; i < vCount * 4; i++)
	{
		float f0 = vData[i];
		if (pos == 0)
		{
			if (f0 > maxw) maxw = f0;
			f0 = f0 + x;
		}
		vertices0.push_back(f0);

		pos++;
		if (pos > 3) pos = 0;
	}
	return maxw;
}


TextComposer::TextComposer(std::string text)
{
	_text = text;
	Compose();
}


TextComposer::~TextComposer() {
	delete _vertices0;
}