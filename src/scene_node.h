#ifndef SCENE_NODE_H
#define SCENE_NODE_H

#include <vector>
#include <memory>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include "resource_holder.cpp"
#include "textures.cpp"
#include "category.cpp"
#include "command.cpp"

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable {
  public:
    typedef std::unique_ptr<SceneNode> NodePtr;
    typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
    SceneNode();
    void attachChild(NodePtr child);
    NodePtr detachChild(const SceneNode& child);
    void update(sf::Time dt);
    sf::Transform getWorldTransform() const;
    sf::Vector2f getWorldPosition() const;
    virtual unsigned int getCategory() const;
    void onCommand(const Command& command, sf::Time dt);

  private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt);
    void updateChildren(sf::Time dt) const;

  private:
    std::vector<NodePtr> children;
    SceneNode* parent;
};
#endif
