#ifndef XTHREE_FACE_NORMALS_HELPER_HPP
#define XTHREE_FACE_NORMALS_HELPER_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xobject3d.hpp"

namespace xthree
{
    //
    // face_normals_helper declaration
    //

    template<class D>
    class xface_normals_helper : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, object);
        XPROPERTY(double, derived_type, size, 1);
        XPROPERTY(xw::html_color, derived_type, color, "0xffff00");
        XPROPERTY(double, derived_type, linewidth, 1);


    protected:

        xface_normals_helper();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using face_normals_helper = xw::xmaterialize<xface_normals_helper>;

    using face_normals_helper_generator = xw::xgenerator<xface_normals_helper>;

    //
    // face_normals_helper implementation
    //


    template <class D>
    inline void xface_normals_helper<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(object, state, buffers);
        xw::set_patch_from_property(size, state, buffers);
        xw::set_patch_from_property(color, state, buffers);
        xw::set_patch_from_property(linewidth, state, buffers);
    }

    template <class D>
    inline void xface_normals_helper<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(object, patch, buffers);
        xw::set_property_from_patch(size, patch, buffers);
        xw::set_property_from_patch(color, patch, buffers);
        xw::set_property_from_patch(linewidth, patch, buffers);
    }

    template <class D>
    inline xface_normals_helper<D>::xface_normals_helper()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xface_normals_helper<D>::set_defaults()
    {
        this->_model_name() = "FaceNormalsHelperModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xface_normals_helper));
//}
#endif