/**
 * Teoria dos Grafos e Computabilidade
 * Trabalho 1 
 * Participantes: Gabriel Xavier, Pedro Tinoco...
 */

#include "graph.hpp"
#include "weighted.hpp"
#include <iostream>
#include <cassert>

void test_basic_graph() {
    std::cout << "Teste 1: Grafo Não Direcionado Não Ponderado" << std::endl;
    
    // Criando grafo simples
    graph g(6, false); // 6 vértices, não direcionado
    
    // Adicionando vértices com rótulos
    g.add_vertex("A");
    g.add_vertex("B"); 
    g.add_vertex("C");
    g.add_vertex("D");
    g.add_vertex("E");
    g.add_vertex("F");
    
    // Adicionando arestas para formar um grafo
    g.add_edge(0, 1); // A-B
    g.add_edge(0, 2); // A-C
    g.add_edge(1, 3); // B-D
    g.add_edge(2, 4); // C-E
    g.add_edge(3, 5); // D-F
    g.add_edge(4, 5); // E-F
    
    std::cout << "Estrutura do grafo:" << std::endl;
    g.print_raw();
    
    // Teste
    assert(g.has_edge(0, 1) == true);
    assert(g.has_edge(1, 0) == true);
    assert(g.has_edge(0, 3) == false);
    
    std::cout << "✓ Teste de grafo não direcionado não ponderado sem problema" << std::endl << std::endl;
}

void test_directed_graph() {
    std::cout << "Teste 2: Grafo Direcionado Não Ponderado" << std::endl;
    
    // Grafo direcionado
    graph dg(5, true); // 5 vértices, direcionado
    
    dg.add_vertex("Root");
    dg.add_vertex("N1");
    dg.add_vertex("N2");
    dg.add_vertex("N3");
    dg.add_vertex("N4");
    
    // Criando grafo
    dg.add_edge(0, 1); // Root -> N1
    dg.add_edge(0, 2); // Root -> N2
    dg.add_edge(1, 3); // N1 -> N3
    dg.add_edge(2, 4); // N2 -> N4
    dg.add_edge(1, 4); // N1 -> N4 (aresta adicional)
    
    std::cout << "Grafo direcionado:" << std::endl;
    dg.print_raw();
    
    // Teste
    assert(dg.has_edge(0, 1) == true);
    assert(dg.has_edge(1, 0) == false); // direcionado
    
    std::cout << "✓ Teste de grafo direcionado sem problema" << std::endl << std::endl;
}

void test_weighted_graph() {
    std::cout << "Teste 3: Grafo Não Direcionado Ponderado" << std::endl;
    
    // Grafo ponderado
    weightedGraph wg(6, false);
    
    wg.add_vertex("A");
    wg.add_vertex("B");
    wg.add_vertex("C");
    wg.add_vertex("D");
    wg.add_vertex("E");
    wg.add_vertex("F");
    
    // Adicionando arestas com pesos
    wg.add_edge(0, 1, 4.0);  // A-B: peso 4
    wg.add_edge(0, 2, 2.0);  // A-C: peso 2
    wg.add_edge(1, 2, 1.0);  // B-C: peso 1
    wg.add_edge(1, 3, 5.0);  // B-D: peso 5
    wg.add_edge(2, 3, 8.0);  // C-D: peso 8
    wg.add_edge(2, 4, 10.0); // C-E: peso 10
    wg.add_edge(3, 4, 2.0);  // D-E: peso 2
    wg.add_edge(3, 5, 6.0);  // D-F: peso 6
    wg.add_edge(4, 5, 3.0);  // E-F: peso 3
    
    std::cout << "Grafo ponderado:" << std::endl;
    wg.print_raw();
    
    // Teste
    assert(wg.has_edge(0, 1) == true);
    assert(wg.has_edge(1, 0) == true);
    
    std::cout << "✓ Teste de grafo ponderado sem problema" << std::endl << std::endl;
}

void test_weighted_directed_graph() {
    std::cout << "Teste 4: Grafo Direcionado Ponderado" << std::endl;
    
    // Grafo direcionado ponderado
    weightedGraph wdg(5, true);
    
    wdg.add_vertex("Root");
    wdg.add_vertex("A");
    wdg.add_vertex("B");
    wdg.add_vertex("C");
    wdg.add_vertex("D");
    
    // Construindo grafo
    wdg.add_edge(0, 1, 10.0); // Root -> A: peso 10
    wdg.add_edge(0, 2, 20.0); // Root -> B: peso 20
    wdg.add_edge(0, 3, 30.0); // Root -> C: peso 30
    wdg.add_edge(1, 2, 40.0); // A -> B: peso 40
    wdg.add_edge(1, 3, 50.0); // A -> C: peso 50
    wdg.add_edge(1, 4, 60.0); // A -> D: peso 60
    wdg.add_edge(2, 3, 70.0); // B -> C: peso 70
    wdg.add_edge(2, 4, 80.0); // B -> D: peso 80
    wdg.add_edge(3, 4, 90.0); // C -> D: peso 90
    
    std::cout << "Grafo direcionado ponderado:" << std::endl;
    wdg.print_raw();
    
    assert(wdg.has_edge(0, 1) == true);
    assert(wdg.has_edge(1, 0) == false); // direcionado
    
    std::cout << "✓ Teste de grafo direcionado ponderado sem problema" << std::endl << std::endl;
}

int main() {
    std::cout << "Testes para Implementação de Grafos" << std::endl;
    std::cout << "=============================================" << std::endl << std::endl;
    
    try {
        test_basic_graph();
        test_directed_graph();
        test_weighted_graph();
        test_weighted_directed_graph();
        
        std::cout << "=============================================" << std::endl;

        
    } catch (const std::exception& e) {
        std::cout << "❌ Erro" << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}