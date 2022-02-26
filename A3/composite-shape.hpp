#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace arteev
{
  class CompositeShape: public Shape
  {
  public:
    using UniqueShape = std::unique_ptr< UniquePtr[] >;
    CompositeShape(const CompositeShape& other);
    CompositeShape(CompositeShape&& other) noexcept = default;
    explicit CompositeShape(UniquePtr shape);
    ~CompositeShape() override = default;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    UniquePtr clone() const override;
    void move(const point_t point) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    std::string getName() const override;
  private:
    int capacity_;
    int size_;
    UniqueShape array_;
  };
}

#endif
