#ifndef XTHREE_BASE_BUFFER_GEOMETRY_HPP
#define XTHREE_BASE_BUFFER_GEOMETRY_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"

namespace xthree
{
    //
    // base_buffer_geometry declaration
    //

    template<class D>
    class xbase_buffer_geometry : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(std::string, derived_type, name, "");
        XPROPERTY(std::string, derived_type, type, "");


    protected:

        xbase_buffer_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using base_buffer_geometry = xw::xmaterialize<xbase_buffer_geometry>;

    using base_buffer_geometry_generator = xw::xgenerator<xbase_buffer_geometry>;

    //
    // base_buffer_geometry implementation
    //


    template <class D>
    inline void xbase_buffer_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(name, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xbase_buffer_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(name, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xbase_buffer_geometry<D>::xbase_buffer_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xbase_buffer_geometry<D>::set_defaults()
    {
        this->_model_name() = "BaseBufferGeometryModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xbase_buffer_geometry));
//}
#endif