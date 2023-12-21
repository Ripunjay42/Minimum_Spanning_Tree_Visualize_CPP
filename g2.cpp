
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <cmath>
using namespace std;
using namespace sf;

#define edge pair<int, int>

class Graph 
{
   
  private:
      vector<pair<int, edge> > G;
      vector<pair<int, edge> > T; 
      int *parent;
      int v;
  public:
    Graph(int v)
    {
        parent = new int[v];
        for (int i = 0; i < v; i++)
            parent[i] = i;
    }


    void AddWeightedEdge(int src, int des, int w)
    {
        G.push_back(make_pair(w, edge(src, des)));
    }


    int find_set(int i)
    {
        if (i == parent[i])
          return i;
        else
          return find_set(parent[i]);
    }


    void union_set(int src, int des)
    {
        parent[src] = parent[des];
    }


    void kruskal()
    {
        int i, uRep, vRep;
        sort(G.begin(), G.end());
        for (i = 0; i < G.size(); i++) 
        {
          uRep = find_set(G[i].second.first);
          vRep = find_set(G[i].second.second);
          if (uRep != vRep) 
          {
            T.push_back(G[i]);
            union_set(uRep, vRep);
          }
        }
    }

    void print_g()
    {
        cout<<"<----Actual Graph---->"<<endl;
        cout << " Edge :"<< " Weight" << endl;
        for (int i = 0; i < G.size(); i++) 
        {
            cout << G[i].second.first << " - " << G[i].second.second << " : "<< G[i].first;
            cout << endl;
        }
        cout<<endl;
    }

    void print_mst()
    {
        int s=0;
        cout<<"<----MST---->"<<endl;
        cout << " Edge :"<< " Weight" << endl;
        for (int i = 0; i < T.size(); i++) 
        {
            cout << T[i].second.first << " - " << T[i].second.second << " : "<< T[i].first;
            cout << endl;
            s+=T[i].first;
        }
        cout<<endl;
        cout<<"total weight of MST==>"<<s<<endl;
    }

    void drawGraph(int n) 
    {
            const float radius = 15.0f;

            RenderWindow window(VideoMode(800, 600), "Given Graph");


            vector<CircleShape> verticesShapes(n);
            for (int i = 0; i < n; ++i) 
            {
                verticesShapes[i].setRadius(radius);
                verticesShapes[i].setPosition(400.0f + 200.0f * std::cos(2.0f * 3.14159f * i / n),
                                            300.0f + 200.0f * std::sin(2.0f * 3.14159f * i / n));
                verticesShapes[i].setFillColor(sf::Color::Blue);
                verticesShapes[i].setOrigin(radius, radius); // Set the origin to the center of the circle
            }


        vector<VertexArray> edgesLines;
        for (auto i:G) 
        {
            {
                  VertexArray line(Lines, 2);
                  line[0].position = Vector2f(verticesShapes[i.second.first].getPosition().x, verticesShapes[i.second.first].getPosition().y);
                  line[1].position = Vector2f(verticesShapes[i.second.second].getPosition().x, verticesShapes[i.second.second].getPosition().y);
                  edgesLines.push_back(line);
            }
        }

        vector<Text> vertexLabels(n);
        Font font;
        font.loadFromFile("C:\\SFML-2.6.1\\arial.ttf"); 
        for (int i = 0; i < n; ++i) 
        {
            vertexLabels[i].setFont(font);
            vertexLabels[i].setCharacterSize(20);
            vertexLabels[i].setFillColor(Color::White);
            vertexLabels[i].setString(to_string(i));
            vertexLabels[i].setPosition(verticesShapes[i].getPosition() + Vector2f(-6, -14));
        }
        
        while (window.isOpen()) 
        {
            Event event;
            while (window.pollEvent(event)) 
            {
                if (event.type == Event::Closed)
                    window.close();
            }

            window.clear();
            for (const auto& line : edgesLines) 
            {
                  window.draw(line);
            }

            for (const auto& vertex : verticesShapes) 
            {
                  window.draw(vertex);
            }
            for (const auto& label : vertexLabels) 
            {
                  window.draw(label);
            }

            window.display();
            
        }
    }

    void drawMst(int n) 
    {
            const float radius = 15.0f;

            RenderWindow window(VideoMode(800, 600), "MST");


            vector<CircleShape> verticesShapes(n);
            for (int i = 0; i < n; ++i) 
            {
                verticesShapes[i].setRadius(radius);
                verticesShapes[i].setPosition(400.0f + 200.0f * std::cos(2.0f * 3.14159f * i / n),
                                            300.0f + 200.0f * std::sin(2.0f * 3.14159f * i / n));
                verticesShapes[i].setFillColor(sf::Color::Blue);
                verticesShapes[i].setOrigin(radius, radius); // Set the origin to the center of the circle
            }


        vector<VertexArray> edgesLines;
        for (auto i:T) 
        {
            {
                  VertexArray line(Lines, 2);
                  line[0].position = Vector2f(verticesShapes[i.second.first].getPosition().x, verticesShapes[i.second.first].getPosition().y);
                  line[1].position = Vector2f(verticesShapes[i.second.second].getPosition().x, verticesShapes[i.second.second].getPosition().y);
                  edgesLines.push_back(line);
            }
        }

        vector<Text> vertexLabels(n);
        Font font;
        font.loadFromFile("C:\\SFML-2.6.1\\arial.ttf"); 
        for (int i = 0; i < n; ++i) 
        {
            vertexLabels[i].setFont(font);
            vertexLabels[i].setCharacterSize(20);
            vertexLabels[i].setFillColor(Color::White);
            vertexLabels[i].setString(to_string(i));
            vertexLabels[i].setPosition(verticesShapes[i].getPosition() + Vector2f(-6, -14));
        }
        
        while (window.isOpen()) 
        {
            Event event;
            while (window.pollEvent(event)) 
            {
                if (event.type == Event::Closed)
                    window.close();
            }

            window.clear();
            for (const auto& line : edgesLines) 
            {
                  window.draw(line);
            }

            for (const auto& vertex : verticesShapes) 
            {
                  window.draw(vertex);
            }
            for (const auto& label : vertexLabels) 
            {
                  window.draw(label);
            }

            window.display();
            
        }
    }
};
int main() 
{
  Graph g(6);
  g.AddWeightedEdge(0, 1, 4);
  g.AddWeightedEdge(0, 2, 4);
  g.AddWeightedEdge(1, 2, 7);
  g.AddWeightedEdge(1, 0, 4);
  g.AddWeightedEdge(2, 0, 4);
  g.AddWeightedEdge(2, 1, 8);
  g.AddWeightedEdge(2, 3, 3);
  g.AddWeightedEdge(2, 5, 8);
  g.AddWeightedEdge(2, 4, 4);
  g.AddWeightedEdge(3, 2, 3);
  g.AddWeightedEdge(3, 4, 3);
  g.AddWeightedEdge(4, 2, 4);
  g.AddWeightedEdge(4, 3, 3);
  g.AddWeightedEdge(5, 2, 8);
  g.AddWeightedEdge(5, 4, 3);
  g.print_g();
  g.drawGraph(6);

  g.kruskal();
  g.print_mst();
  g.drawMst(6);

  return 0;
}

