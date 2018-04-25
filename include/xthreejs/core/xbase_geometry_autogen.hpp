#ifndef XTHREE_BASE_GEOMETRY_HPP
#define XTHREE_BASE_GEOMETRY_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"

namespace xthree
{
    //
    // base_geometry declaration
    //

    template<class D>
    class xbase_geometry : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(std::string, derived_type, name, "");
        XPROPERTY(std::string, derived_type, type, "");

    protected:

        xbase_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using base_geometry = xw::xmaterialize<xbase_geometry>;

    using base_geometry_generator = xw::xgenerator<xbase_geometry>;

    //
    // base_geometry implementation
    //

    template <class D>
    inline void xbase_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(name, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xbase_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(name, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xbase_geometry<D>::xbase_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xbase_geometry<D>::set_defaults()
    {
        this->_model_name() = "BaseGeometryModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xbase_geometry));
//}
#endif