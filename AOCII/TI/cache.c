#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "cache.h"

void init_info(int conjs, int vias) //calculos das informacoes da cache e ram 
{
    ic.Bytes_Palavra = PalavraBloco;
    ic.Palavra_Bloco = BytePalavra;
    ic.Tam_Bloco = ic.Bytes_Palavra * ic.Palavra_Bloco;

    ic.Num_Conjs = conjs;
    ic.Vias = vias;
    ic.Capac_Conj = ic.Vias * ic.Tam_Bloco;
    ic.Capac_User = ic.Num_Conjs * ic.Capac_Conj; //Capacidade do User em bytes

    ic.Tam_Endereco = TamEndereco;
    ic.Byte_Offset = log2(ic.Bytes_Palavra);
    ic.Word_Offset = log2(ic.Palavra_Bloco);
    ic.Index = log2(ic.Num_Conjs);
    ic.Bit_Valid = BitsVeD;
    ic.Bit_Dirt = BitsVeD;
    ic.Tag = ic.Tam_Endereco - ic.Index - ic.Word_Offset - ic.Byte_Offset;

    ic.Tam_Overhead = ic.Num_Conjs * (ic.Vias * (ic.Tag + ic.Bit_Valid + ic.Bit_Dirt)); //bits
    ic.Tam_Overhead /= 8; //Overhead em bytes
    ic.Tam_Overhead /= 1024; //Overhead em KB
    ic.Capac_User /= 1024; //Capacidade do User em KB
    ic.Tam_MemTotal = ic.Capac_User + ic.Tam_Overhead; //Memoria Total em KB

    // RAM
    ic.Byte_Offset = log2(BytePalavra);
    ic.Word_Offset = log2(PalavraBloco);
    
    ir.Num_Conjs = (ic.Vias * ic.Num_Conjs) * 4;

    ir.Bloco_Offset = log2(ir.Num_Conjs); //5
    ir.Index_Offset = ic.Index; //3
    ir.Tag_Offset = ir.Bloco_Offset - ir.Index_Offset; //2
}

void infoCachePrint() //print informacoes da cache e ram 
{
    printf("Bytes por Palavra: ");
    printf("%i\n", ic.Bytes_Palavra);
    printf("Palavras por Bloco: ");
    printf("%i\n", ic.Palavra_Bloco);
    printf("Tamanho do Bloco: ");
    printf("%i\n", ic.Tam_Bloco);
    printf("Numero de Vias (Informado): ");
    printf("%i\n", ic.Vias);
    printf("Capacidade de um Conjunto: ");
    printf("%i\n", ic.Capac_Conj);
    printf("Numero de Conjuntos (Informado): ");
    printf("%i\n", ic.Num_Conjs);
    printf("Capacidade do Usuario: ");
    printf("%.2f KB - ", ic.Capac_User);
    printf("%.0f bytes\n", ic.Capac_User*1024);
    printf("Tamanho do Overhead: ");
    printf("%.2f KB - ", ic.Tam_Overhead);
    printf("%.0f bytes\n", ic.Tam_Overhead*1024);
    printf("Tamanho da Memoria Total: ");
    printf("%.2f KB - ", ic.Tam_MemTotal);
    printf("%.0f bytes\n\n", ic.Tam_MemTotal*1024);

    printf("Tamanho do Endereco: ");
    printf("%i\n", ic.Tam_Endereco);
    printf("Byte Offset: ");
    printf("%i\n", ic.Byte_Offset);
    printf("Word Offset: ");
    printf("%i\n", ic.Word_Offset);
    printf("Index: ");
    printf("%i\n", ic.Index);
    printf("Tag: ");
    printf("%i\n", ic.Tag);
    printf("Bit de Validade: ");
    printf("%i\n", ic.Bit_Valid);
    printf("Bit de Bit_Dirt (Write-Back): ");
    printf("%i\n\n", ic.Bit_Dirt);
    printf("Numero de Conjuntos da RAM(Informado): ");
    printf("%i\n", ir.Num_Conjs);
}

void init_cache() //inicializacao da cache e ram
{
    c1 = (cache*)malloc(sizeof(cache) * (ic.Num_Conjs*ic.Vias));
    for (int i = 0; i < ic.Num_Conjs*ic.Vias; i++)
    {
        c1[i].Bit_Dirt = 0;
        c1[i].Bit_Valid = 0;
        c1[i].Index = i;
        c1[i].Tag = 0; //a Tag é de 0 até 2^Num_Tag??
        for (int j = 0; j < BytePalavra; j++)
        {
            strcpy(c1[i].ConteudoInstr[j].opcode, "opc");
            strcpy(c1[i].ConteudoInstr[j].rd, "$rd");
            strcpy(c1[i].ConteudoInstr[j].rs, "$rs");
            strcpy(c1[i].ConteudoInstr[j].rt, "$rt");
            c1[i].CounteudoData[j] = 0;
            c1[i].ConteudoInstr[j].immed = 0;
            c1[i].Byte_Offset[j] = j;
            c1[i].Word_Offset[j] = j;
        }
    }
    
    r1 = (ram*)malloc(sizeof(ram) * ir.Num_Conjs);
    for (int i = 0; i < ir.Num_Conjs; i++)
    {
        r1[i].Bloco = i; //??????
        for (int j = 0; j < BytePalavra; j++)
        {
            strcpy(r1[i].ConteudoInstr[j].opcode, "opc");
            strcpy(r1[i].ConteudoInstr[j].rd, "$rd");
            strcpy(r1[i].ConteudoInstr[j].rs, "$rs");
            strcpy(r1[i].ConteudoInstr[j].rt, "$rt");
            r1[i].CounteudoData[j] = 0;
            r1[i].ConteudoInstr[j].immed = 0;
            r1[i].Byte_Offset[j] = j;
            r1[i].Word_Offset[j] = j;
        }
    }
    printf("\nCache e RAM inicializados!\n");
}

//////////////mips

void init_mips_regs() //inicializa e nomeia os registradores do mips 
{
    strcpy(mipsReg[0].nome, "$zr");
    strcpy(mipsReg[1].nome, "$at");
    strcpy(mipsReg[2].nome, "$v0");
    strcpy(mipsReg[3].nome, "$v1");
    strcpy(mipsReg[4].nome, "$a0");
    strcpy(mipsReg[5].nome, "$a1");
    strcpy(mipsReg[6].nome, "$a2");
    strcpy(mipsReg[7].nome, "$a3");
    strcpy(mipsReg[8].nome, "$t0");
    strcpy(mipsReg[9].nome, "$t1");
    strcpy(mipsReg[10].nome, "$t2");
    strcpy(mipsReg[11].nome, "$t3");
    strcpy(mipsReg[12].nome, "$t4");
    strcpy(mipsReg[13].nome, "$t5");
    strcpy(mipsReg[14].nome, "$t6");
    strcpy(mipsReg[15].nome, "$t7");
    strcpy(mipsReg[16].nome, "$s0");
    strcpy(mipsReg[17].nome, "$s1");
    strcpy(mipsReg[18].nome, "$s2");
    strcpy(mipsReg[19].nome, "$s3");
    strcpy(mipsReg[20].nome, "$s4");
    strcpy(mipsReg[21].nome, "$s5");
    strcpy(mipsReg[22].nome, "$s6");
    strcpy(mipsReg[23].nome, "$s7");
    strcpy(mipsReg[24].nome, "$t8");
    strcpy(mipsReg[25].nome, "$t9");
    strcpy(mipsReg[26].nome, "$k0");
    strcpy(mipsReg[27].nome, "$k1");
    strcpy(mipsReg[28].nome, "$gp");
    strcpy(mipsReg[29].nome, "$sp");
    strcpy(mipsReg[30].nome, "$fp");
    strcpy(mipsReg[31].nome, "$ra");
    for (int i = 0; i < 32; i++)
    {
        mipsReg[i].valor = 0;
    }
    printf("\nRegistradores do MIPS inicializados!\n");
}

void MIPS_print()
{
    printf("\nRegistradores MIPS\n");
    for (int i = 0; i < 32; i++)
    {
        printf("%s: %d\n", mipsReg[i].nome, mipsReg[i].valor);
    }
}

void init_instructions()
{
    instructionsFile = fopen("instructions.txt", "r");
    if (instructionsFile == NULL)
    {
        printf("\nErro de leitura do arquivo!\n");
    }
    else
    {
        for (char c = getc(instructionsFile); c != EOF; c = getc(instructionsFile))
			if(c == '\n') quant_instruc++;
		rewind(instructionsFile);

		Instructions = (instruct*)malloc(sizeof(instruct)*quant_instruc);
        quant_instruc +=1;
        
        char tmp[3];
        //int x = 0;
        for(int x = 0; fgetc(instructionsFile) != EOF; x++)
        {
            fseek(instructionsFile, -1, SEEK_CUR);
            fscanf(instructionsFile, "%s ", tmp);

            if(strcmp(tmp, "add") == 0)
            {
                strcpy(Instructions[x].opcode, tmp);
                fscanf (instructionsFile, " %3s %3s %3s", Instructions[x].rd, &Instructions[x].rs, Instructions[x].rt);
                //printf("%s %s %s %s\n", Instructions[x].opcode, Instructions[x].rd, Instructions[x].rs, Instructions[x].rt);
            }
            else if(strcmp(tmp, "lw") == 0)
            {
                strcpy(Instructions[x].opcode, tmp);
                fscanf (instructionsFile, " %3s %d %3s", Instructions[x].rs, &Instructions[x].immed, Instructions[x].rt);
                //printf("%s %s %d %s\n", Instructions[x].opcode, Instructions[x].rs, Instructions[x].immed, Instructions[x].rt);
            }
            else if(strcmp(tmp, "sw") == 0)
            {
                strcpy(Instructions[x].opcode, tmp);
                fscanf (instructionsFile, " %3s %d %3s", Instructions[x].rs, &Instructions[x].immed, Instructions[x].rt);
                //printf("%s %s %d %s\n", Instructions[x].opcode, Instructions[x].rs, Instructions[x].immed, Instructions[x].rt);
            }
            else
            {
                printf("\nErro! Instrucao desconhecida!\n");
            }
            //x++;
        }
        for (int i = 0; i < quant_instruc; i++)
        {
            if(strcmp(Instructions[i].opcode, "add") == 0) 
            {
                //printf("%s %s %s %s\n", Instructions[i].opcode, Instructions[i].rd, Instructions[i].rs, Instructions[i].rt);
            }
            //if(strcmp(Instructions[i].opcode, "lw") == 0)
            //{
                //printf("%s %s %d %s\n", Instructions[i].opcode, Instructions[i].rs, Instructions[i].immed, Instructions[i].rt);
            //}
            //if(strcmp(Instructions[i].opcode, "sw") == 0)
            //{
                //printf("%s %s %d %s\n", Instructions[i].opcode, Instructions[i].rs, Instructions[i].immed, Instructions[i].rt);
            //}
        }
    }
	fclose(instructionsFile);
    printf("\nInstrucoes inicializadas!\n");
}

void load_RAM()
{
    int k = 0;
    for (int i = 0; i < (quant_instruc/4)+1; i++)
    {
        for (int j = 0; j < BytePalavra; j++)
        {
            r1[i].ConteudoInstr[j].immed = Instructions[k].immed;
            strcpy(r1[i].ConteudoInstr[j].opcode, Instructions[k].opcode);
            strcpy(r1[i].ConteudoInstr[j].rd, Instructions[k].rd);
            strcpy(r1[i].ConteudoInstr[j].rs, Instructions[k].rs);
            strcpy(r1[i].ConteudoInstr[j].rt, Instructions[k].rt);
            k++;
        }
        
    }
    printf("\nRAM Carregada!\n");
}

void RAM_print()
{
    printf("\nRAM\n");
    for (int i = 0; i < ir.Num_Conjs/2; i++)
    {
        for (int j = 0; j < BytePalavra; j++)
        {
            printf("%i. %i \t", r1[i].Bloco, r1[i].Word_Offset[j]);
            if(strcmp(r1[i].ConteudoInstr[j].opcode, "add") == 0)
            {
                printf("%s %s %s %s\n", r1[i].ConteudoInstr[j].opcode, r1[i].ConteudoInstr[j].rd, r1[i].ConteudoInstr[j].rs, r1[i].ConteudoInstr[j].rt);
            }
            else if(strcmp(r1[i].ConteudoInstr[j].opcode, "lw") == 0)
            {
                printf("%s %s %d %s\n", r1[i].ConteudoInstr[j].opcode, r1[i].ConteudoInstr[j].rs, r1[i].ConteudoInstr[j].immed, r1[i].ConteudoInstr[j].rt);
            }
            else if(strcmp(r1[i].ConteudoInstr[j].opcode, "sw") == 0)
            {
                printf("%s %s %d %s\n", r1[i].ConteudoInstr[j].opcode, r1[i].ConteudoInstr[j].rs, r1[i].ConteudoInstr[j].immed, r1[i].ConteudoInstr[j].rt);
            }
            else{
                printf("%d %d %d %d\n", r1[i].CounteudoData[0], r1[i].CounteudoData[1], r1[i].CounteudoData[2], r1[i].CounteudoData[3]);
            }
        }
    }
}

void CACHE_print()
{
    printf("\nCACHE\n");
    printf("bD bV / Index Word / Conteudo\n");
    for (int i = 0; i < ic.Num_Conjs*ic.Vias; i++)
    {
        for (int j = 0; j < BytePalavra; j++)
        {
            printf("%i %i / %i. %i \t", c1[i].Bit_Dirt, c1[i].Bit_Valid, c1[i].Index, c1[i].Word_Offset[j]);

            if(strcmp(c1[i].ConteudoInstr[j].opcode, "add") == 0)
            {
                printf("%s %s %s %s\n", c1[i].ConteudoInstr[j].opcode, c1[i].ConteudoInstr[j].rd, c1[i].ConteudoInstr[j].rs, c1[i].ConteudoInstr[j].rt);
            }
            else if(strcmp(c1[i].ConteudoInstr[j].opcode, "lw") == 0)
            {
                printf("%s %s %d %s\n", c1[i].ConteudoInstr[j].opcode, c1[i].ConteudoInstr[j].rs, c1[i].ConteudoInstr[j].immed, c1[i].ConteudoInstr[j].rt);
            }
            else if(strcmp(c1[i].ConteudoInstr[j].opcode, "sw") == 0)
            {
                printf("%s %s %d %s\n", c1[i].ConteudoInstr[j].opcode, c1[i].ConteudoInstr[j].rs, c1[i].ConteudoInstr[j].immed, c1[i].ConteudoInstr[j].rt);
            }
            else{
                printf("%d\n", c1[i].CounteudoData[j]);
            }
        }
    }
}

void pull(int i)
{
    int end;
    end = r1[i].Bloco%ic.Num_Conjs;


    /*if(c1[end].Bit_Dirt == 1)
    {
        for (int j = 0; j < BytePalavra; j++)
        {
            r1[i].CounteudoData[j] = c1[end].CounteudoData[j];
            r1[i].ConteudoInstr[j].immed = c1[end].ConteudoInstr[0].immed;
            strcpy(r1[i].ConteudoInstr[j].opcode, c1[end].ConteudoInstr[j].opcode);
            strcpy(r1[i].ConteudoInstr[j].rd, c1[end].ConteudoInstr[j].rd);
            strcpy(r1[i].ConteudoInstr[j].rs, c1[end].ConteudoInstr[j].rs);
            strcpy(r1[i].ConteudoInstr[j].rt, c1[end].ConteudoInstr[j].rt);
        }
        c1[end].Bit_Dirt = 0;
    }*/
    c1[end].Bit_Valid = 1;
    for (int j = 0; j < BytePalavra; j++)
    {
        c1[end].CounteudoData[j] = r1[i].CounteudoData[j];
        c1[end].ConteudoInstr[j].immed = r1[i].ConteudoInstr[j].immed;
        strcpy(c1[end].ConteudoInstr[j].opcode, r1[i].ConteudoInstr[j].opcode);
        strcpy(c1[end].ConteudoInstr[j].rd, r1[i].ConteudoInstr[j].rd);
        strcpy(c1[end].ConteudoInstr[j].rs, r1[i].ConteudoInstr[j].rs);
        strcpy(c1[end].ConteudoInstr[j].rt, r1[i].ConteudoInstr[j].rt);
    }
    pc++;
}


pc = 0;


void processor()
{
    if (strcmp(c1[pc].ConteudoInstr[0].opcode, "opc") == 0)
    {
        pull(pc);
    }
}

void processor2()
{
    if(strcmp(c1[pc].ConteudoInstr[0].opcode, "add") == 0)
    {
        inst_add(c1[pc].Index , c1[pc].Word_Offset[0]);
    }
    else if(strcmp(c1[pc].ConteudoInstr[0].opcode, "lw") == 0)
    {
        inst_lw(c1[pc].Index , c1[pc].Word_Offset[0]);
    }
}

void inst_add(int bloco, int word)
{
    int d, s, t;
    for (int i = 0; i < 32; i++)
    {
        if (strcmp(c1[bloco].ConteudoInstr[word].rs, mipsReg[i].nome) == 0)
        {
            s = mipsReg[i].valor;
        }
        if (strcmp(c1[bloco].ConteudoInstr[word].rt, mipsReg[i].nome) == 0)
        {
            t = mipsReg[i].valor;
        }
    }
    d = s + t;
    for (int i = 0; i < 32; i++)
    {
        if (strcmp(c1[bloco].ConteudoInstr[word].rd, mipsReg[i].nome) == 0)
        {
            mipsReg[i].valor = d;
        }
    }
}

void inst_lw(int bloco, int word)
{
    int s, i, t;
    i = c1[bloco].ConteudoInstr[word].immed;
    for (int j = 0; j < 32; j++)
    {
        if (strcmp(c1[bloco].ConteudoInstr[word].rt, mipsReg[j].nome) == 0)
        {
            printf("%s\n", mipsReg[j].nome);
            t = mipsReg[i].valor;
        }
    }
    int xesq = i + t;
    int j=0, k=0, z=0;
    while (z != xesq)
    {
        
        k++;
        if (k > 3)
        {
            k = 0;
            j++;
        }
        z++;
    }
    printf("%d %d %d\n", xesq, j, k-1);
    
    for (int l = 0; l < 32; l++)
    {
        if (strcmp(c1[bloco].ConteudoInstr[word].rs, mipsReg[l].nome) == 0)
        {
            mipsReg[l].valor = c1[j].CounteudoData[k-1];
        }
    }
}